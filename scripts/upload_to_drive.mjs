import fs from "fs";
import path from "path";
import { fileURLToPath } from "url";

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const ROOT_DIR = path.resolve(__dirname, "..");
const BRIEFINGS_DIR = path.join(ROOT_DIR, "briefings");

const credentialsPath = path.join(process.env.USERPROFILE || "", ".gdrive-server-credentials.json");
const oauthPath = path.join(process.env.USERPROFILE || "", ".gdrive-credentials.json");
const TARGET_FOLDER_ID = "1DrXUosZl3_Ihh8Ud2ZTW83aL6g7NA-iu"; // briefings folder in Google Drive

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

async function uploadFile(fileName, content, folderId, mimeType = "text/markdown") {
  const token = await getAccessToken();
  const metadata = {
    name: fileName,
    mimeType: mimeType,
    parents: [folderId],
  };

  const boundary = "-------314159265358979323846";
  const delimiter = "\r\n--" + boundary + "\r\n";
  const closeDelim = "\r\n--" + boundary + "--";

  const multipartRequestBody =
    delimiter +
    "Content-Type: application/json; charset=UTF-8\r\n\r\n" +
    JSON.stringify(metadata) +
    delimiter +
    `Content-Type: ${mimeType}\r\n\r\n` +
    content +
    closeDelim;

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
  console.log(`Starting upload to Google Drive folder ${TARGET_FOLDER_ID}...`);
  const files = fs.readdirSync(BRIEFINGS_DIR).filter((f) => f.endsWith(".md"));

  for (const f of files) {
    const filePath = path.join(BRIEFINGS_DIR, f);
    const content = fs.readFileSync(filePath, "utf-8");
    process.stdout.write(`Uploading ${f} (${(content.length / 1024).toFixed(1)} KB)... `);
    const res = await uploadFile(f, content, TARGET_FOLDER_ID);
    console.log(`Done! (ID: ${res.id})`);
  }

  // Also upload audit report and blueprint
  const auditPath = path.join(ROOT_DIR, "audit", "corpus_audit.md");
  if (fs.existsSync(auditPath)) {
    const content = fs.readFileSync(auditPath, "utf-8");
    process.stdout.write(`Uploading corpus_audit.md... `);
    const res = await uploadFile("corpus_audit.md", content, TARGET_FOLDER_ID);
    console.log(`Done! (ID: ${res.id})`);
  }

  console.log("\nAll files successfully uploaded to Google Drive!");
}

main().catch(console.error);
