import fs from "fs";
import path from "path";
import { fileURLToPath } from "url";

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const ROOT_DIR = path.resolve(__dirname, "..");
const BRIEFINGS_DIR = path.join(ROOT_DIR, "briefings");

const credentialsPath = path.join(process.env.USERPROFILE || "", ".gdrive-server-credentials.json");
const oauthPath = path.join(process.env.USERPROFILE || "", ".gdrive-credentials.json");

// Drive folder hierarchy
const ROOT_FOLDER_ID = "1Z2IAQ7Sf1pZWTn5EniiSBpuH7gLeaWLu";
const BRIEFINGS_FOLDER_ID = "1DrXUosZl3_Ihh8Ud2ZTW83aL6g7NA-iu";
const DATASETS_FOLDER_ID = "10dZZiSWfeFMsl-8mBldwv2ekPmbfm__o";
const LEDGER_FOLDER_ID = "19g4kqH2MmW5kLcdsB840-AYiJONJ8E7P";

async function getAccessToken() {
  if (!fs.existsSync(credentialsPath)) {
    throw new Error(`Credentials file not found at ${credentialsPath}`);
  }
  const creds = JSON.parse(fs.readFileSync(credentialsPath, "utf-8"));

  if (creds.access_token && creds.expiry_date && creds.expiry_date > Date.now() + 60000) {
    return creds.access_token;
  }

  if (creds.refresh_token && fs.existsSync(oauthPath)) {
    const oauth = JSON.parse(fs.readFileSync(oauthPath, "utf-8"));
    const keys = oauth.installed || oauth.web;
    const body = new URLSearchParams({
      client_id: keys.client_id,
      client_secret: keys.client_secret,
      refresh_token: creds.refresh_token,
      grant_type: "refresh_token",
    });

    const res = await fetch("https://oauth2.googleapis.com/token", {
      method: "POST",
      headers: { "Content-Type": "application/x-www-form-urlencoded" },
      body: body.toString(),
    });

    if (!res.ok) {
      throw new Error(`Failed to refresh token: ${await res.text()}`);
    }
    const tokenData = await res.json();
    creds.access_token = tokenData.access_token;
    if (tokenData.expires_in) {
      creds.expiry_date = Date.now() + tokenData.expires_in * 1000;
    }
    fs.writeFileSync(credentialsPath, JSON.stringify(creds, null, 2));
    return creds.access_token;
  }

  return creds.access_token;
}

async function findExistingFiles(fileName, folderId, token) {
  const q = encodeURIComponent(`'${folderId}' in parents and name = '${fileName}' and trashed = false`);
  const res = await fetch(`https://www.googleapis.com/drive/v3/files?q=${q}&fields=files(id,name)`, {
    headers: { Authorization: `Bearer ${token}` },
  });
  if (!res.ok) return [];
  const data = await res.json();
  return data.files || [];
}

async function deleteFile(fileId, token) {
  await fetch(`https://www.googleapis.com/drive/v3/files/${fileId}`, {
    method: "DELETE",
    headers: { Authorization: `Bearer ${token}` },
  });
}

async function uploadOrUpdateFile(fileName, content, folderId, mimeType = "text/markdown") {
  const token = await getAccessToken();

  // Clean up any existing duplicate files with the same name in this folder
  const existing = await findExistingFiles(fileName, folderId, token);
  for (const ef of existing) {
    await deleteFile(ef.id, token);
  }

  const metadata = {
    name: fileName,
    mimeType: mimeType,
    parents: [folderId],
  };

  const boundary = "-------314159265358979323846";
  const delimiter = "\r\n--" + boundary + "\r\n";
  const closeDelim = "\r\n--" + boundary + "--";

  const part1 = Buffer.from(
    delimiter +
      "Content-Type: application/json; charset=UTF-8\r\n\r\n" +
      JSON.stringify(metadata) +
      delimiter +
      `Content-Type: ${mimeType}\r\n\r\n`
  );
  const part2 = Buffer.isBuffer(content) ? content : Buffer.from(content, "utf-8");
  const part3 = Buffer.from(closeDelim);

  const multipartRequestBody = Buffer.concat([part1, part2, part3]);

  const res = await fetch("https://www.googleapis.com/upload/drive/v3/files?uploadType=multipart", {
    method: "POST",
    headers: {
      Authorization: `Bearer ${token}`,
      "Content-Type": `multipart/related; boundary=${boundary}`,
    },
    body: multipartRequestBody,
  });

  if (!res.ok) {
    throw new Error(`Failed to upload ${fileName}: ${await res.text()}`);
  }

  const data = await res.json();
  return data;
}

async function main() {
  console.log("=== Google Drive Synchronization ===");
  console.log(`Root Folder: ${ROOT_FOLDER_ID}`);
  console.log(`Briefings & Warehouse: ${BRIEFINGS_FOLDER_ID}`);
  console.log(`Datasets Folder: ${DATASETS_FOLDER_ID}`);
  console.log(`Ledger Folder: ${LEDGER_FOLDER_ID}\n`);

  // 1. Briefings & Archetypes
  const briefingFiles = fs.readdirSync(BRIEFINGS_DIR).filter((f) => f.endsWith(".md"));
  for (const f of briefingFiles) {
    const filePath = path.join(BRIEFINGS_DIR, f);
    const content = fs.readFileSync(filePath, "utf-8");
    process.stdout.write(`Syncing briefings/${f} (${(content.length / 1024).toFixed(1)} KB)... `);
    const res = await uploadOrUpdateFile(f, content, BRIEFINGS_FOLDER_ID);
    console.log(`Done! (ID: ${res.id})`);
  }

  // 2. Audit Report
  const auditPath = path.join(ROOT_DIR, "audit", "corpus_audit.md");
  if (fs.existsSync(auditPath)) {
    const content = fs.readFileSync(auditPath, "utf-8");
    process.stdout.write(`Syncing audit/corpus_audit.md... `);
    const res = await uploadOrUpdateFile("corpus_audit.md", content, BRIEFINGS_FOLDER_ID);
    console.log(`Done! (ID: ${res.id})`);
  }

  // 3. Warehouse Files
  const warehouseFiles = ["corpus_warehouse.md", "index_map.md"];
  for (const wf of warehouseFiles) {
    const wfPath = path.join(ROOT_DIR, "warehouse", wf);
    if (fs.existsSync(wfPath)) {
      const content = fs.readFileSync(wfPath, "utf-8");
      process.stdout.write(`Syncing warehouse/${wf} (${(content.length / 1024).toFixed(1)} KB)... `);
      const res = await uploadOrUpdateFile(wf, content, BRIEFINGS_FOLDER_ID);
      console.log(`Done! (ID: ${res.id})`);
    }
  }

  // 4. Datasets (JSONL)
  const datasetPath = path.join(ROOT_DIR, "datasets", "cp_instruction_dataset.jsonl");
  if (fs.existsSync(datasetPath)) {
    const content = fs.readFileSync(datasetPath);
    process.stdout.write(`Syncing datasets/cp_instruction_dataset.jsonl (${(content.length / 1024 / 1024).toFixed(2)} MB)... `);
    const res = await uploadOrUpdateFile("cp_instruction_dataset.jsonl", content, DATASETS_FOLDER_ID, "application/jsonl");
    console.log(`Done! (ID: ${res.id})`);
  }

  // 5. SQLite Database (Binary)
  const dbPath = path.join(ROOT_DIR, "ledger", "corpus.db");
  if (fs.existsSync(dbPath)) {
    const content = fs.readFileSync(dbPath);
    process.stdout.write(`Syncing ledger/corpus.db (${(content.length / 1024 / 1024).toFixed(2)} MB)... `);
    const res = await uploadOrUpdateFile("corpus.db", content, LEDGER_FOLDER_ID, "application/vnd.sqlite3");
    console.log(`Done! (ID: ${res.id})`);
  }

  // 6. Ledger Tasks Index
  const tasksIndexPath = path.join(ROOT_DIR, "ledger", "tasks_index.json");
  if (fs.existsSync(tasksIndexPath)) {
    const content = fs.readFileSync(tasksIndexPath, "utf-8");
    process.stdout.write(`Syncing ledger/tasks_index.json (${(content.length / 1024).toFixed(1)} KB)... `);
    const res = await uploadOrUpdateFile("tasks_index.json", content, LEDGER_FOLDER_ID, "application/json");
    console.log(`Done! (ID: ${res.id})`);
  }

  console.log("\nAll assets (briefings, warehouse, datasets, SQLite ledger) fully synced to Google Drive!");
}

main().catch(console.error);
