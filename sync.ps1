<#
.SYNOPSIS
Safely synchronize the IEEE-Xtreme-Archive repository, validate corpus integrity, check for secrets, and commit with semantic conventional messaging.

.DESCRIPTION
Pulls latest changes from origin with rebase and autostash, runs corpus JSON integrity checks,
scans staged changes for accidental secrets or credentials, generates smart conventional commit
messages (feat/fix/docs/harvester/tasks/ledger) based on modified components, and pushes to remote.
#>

[CmdletBinding()]
param (
    [Alias("m")]
    [string]$Message,

    [switch]$PullOnly,

    [switch]$SkipAudit,

    [switch]$NoPush
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

function Write-Status {
    param(
        [string]$Message,
        [System.ConsoleColor]$Color = [System.ConsoleColor]::Cyan
    )
    Write-Host "[$((Get-Date).ToString('HH:mm:ss'))] $Message" -ForegroundColor $Color
}

function Write-Notice {
    param([string]$Message)
    Write-Status -Message $Message -Color ([System.ConsoleColor]::Yellow)
}

function Write-Success {
    param([string]$Message)
    Write-Status -Message $Message -Color ([System.ConsoleColor]::Green)
}

function Find-StagedSecrets {
    $stagedDiff = git diff --cached -U0 2>$null
    if (-not $stagedDiff) { return @() }

    $addedLines = $stagedDiff | Where-Object { $_ -match '^\+[^+]' } | ForEach-Object { $_.Substring(1) }
    if (-not $addedLines) { return @() }

    $secretPatterns = @(
        'AKIA[0-9A-Z]{16}'
        'sk-[a-zA-Z0-9]{20,}'
        'sk-ant-[a-zA-Z0-9\-]{20,}'
        'ghp_[a-zA-Z0-9]{36}'
        'github_pat_[a-zA-Z0-9_]{20,}'
        'AIza[0-9A-Za-z\-_]{35}'
        'xox[baprs]-[0-9a-zA-Z\-]{10,}'
        '-----BEGIN (RSA|EC|OPENSSH|PGP|DSA)? ?PRIVATE KEY-----'
        '(?i)(api[_-]?key|secret|password|token|passwd)\s*[:=]\s*[''"][^''"\s]{8,}[''"]'
    )

    $hits = @()
    foreach ($line in $addedLines) {
        foreach ($pattern in $secretPatterns) {
            if ($line -match $pattern) {
                $snippet = $line.Trim()
                $hits += [PSCustomObject]@{
                    Pattern = $pattern
                    Snippet = $snippet.Substring(0, [Math]::Min(60, $snippet.Length))
                }
                break
            }
        }
    }

    return @($hits)
}

function Validate-CorpusIntegrity {
    Write-Status "Validating corpus JSON files and ledger health..."
    $ledgerFiles = @("ledger/tasks_index.json", "ledger/jobs_queue.json", "ledger/archive_ledger.json")
    foreach ($file in $ledgerFiles) {
        if (Test-Path $file) {
            try {
                $null = Get-Content -Raw $file | ConvertFrom-Json
            } catch {
                throw "Integrity error: Invalid JSON in $file : $_"
            }
        }
    }
    Write-Success "Corpus integrity check passed!"
}

function Get-ArchiveScope {
    param([string[]]$ChangedFiles)

    if ($ChangedFiles | Where-Object { $_ -match 'platforms/csacademy/tasks/[^/]+/submissions' }) { return "solutions" }
    if ($ChangedFiles | Where-Object { $_ -match 'platforms/csacademy/tasks/' }) { return "tasks" }
    if ($ChangedFiles | Where-Object { $_ -match 'ledger/' }) { return "ledger" }
    if ($ChangedFiles | Where-Object { $_ -match 'harvesters/' }) { return "harvester" }
    if ($ChangedFiles | Where-Object { $_ -match 'skills/' }) { return "skills" }
    if ($ChangedFiles | Where-Object { $_ -match 'README\.md|ARCHIVAL_PLAN|docs/' }) { return "docs" }
    if ($ChangedFiles | Where-Object { $_ -match '\.github/|\.gitignore|sync\.ps1' }) { return "config" }
    return "corpus"
}

function Get-AutoCommitMessage {
    $statusLines = git status --porcelain
    if (-not $statusLines) { return $null }

    $modifiedFiles = @()
    foreach ($line in $statusLines) {
        if ($line.Length -ge 4) {
            $modifiedFiles += $line.Substring(3).Trim()
        }
    }

    $scope = Get-ArchiveScope -ChangedFiles $modifiedFiles

    # Check if archive ledger has count stats
    $ledgerPath = "ledger/archive_ledger.json"
    $taskCount = 0
    $jobCount = 0
    if (Test-Path $ledgerPath) {
        try {
            $ledger = Get-Content -Raw $ledgerPath | ConvertFrom-Json
            $taskCount = @($ledger.completed_statements).Count
            $jobCount = $ledger.total_jobs_archived
        } catch {}
    }

    if ($scope -eq "solutions" -or $scope -eq "tasks") {
        return "feat($scope): update archived CP corpus ($taskCount tasks, $jobCount solutions cataloged)"
    }
    if ($scope -eq "harvester") {
        return "feat(harvester): enhance CDP crawler and archival logic"
    }
    if ($scope -eq "skills") {
        return "feat(skills): update cp-archive-harvester skill definition"
    }
    if ($scope -eq "docs") {
        return "docs(archive): update repository status, handover plan, and metrics"
    }
    if ($scope -eq "ledger") {
        return "chore(ledger): update discovery checkpoints and job queue"
    }

    return "chore(corpus): synchronize repository state"
}

# -------------------------------------------------------------
# Main Execution Pipeline
# -------------------------------------------------------------

try {
    Write-Status "Starting IEEE-Xtreme-Archive repository synchronization..."
    
    # Check git repo
    $gitRoot = git rev-parse --show-toplevel 2>$null
    if (-not $gitRoot) {
        throw "Current directory is not a valid Git repository."
    }

    $currentBranch = (git branch --show-current 2>$null)
    if ($currentBranch) { $currentBranch = $currentBranch.Trim() }
    if (-not $currentBranch) { $currentBranch = "main" }

    $hasRemote = [bool](git remote get-url origin 2>$null)
    $remoteBranchExists = if ($hasRemote) { [bool](git ls-remote --heads origin $currentBranch 2>$null) } else { $false }

    # 0. Verification Gate
    if ((-not $SkipAudit) -and (Test-Path "scripts/verify.py")) {
        Write-Status "Running scripts/verify.py..."
        python scripts/verify.py
        if ($LASTEXITCODE -ne 0) {
            throw "scripts/verify.py reported errors. Fix before committing."
        }
    }

    # 1. Safe Pull
    if ($hasRemote -and $remoteBranchExists) {
        Write-Status "Pulling latest remote updates for $currentBranch (rebase + autostash)..."
        git pull origin $currentBranch --rebase --autostash
        Write-Success "Remote pull complete."
    } else {
        Write-Notice "Branch '$currentBranch' is local-only or no remote. Skipping initial pull."
    }

    if ($PullOnly) {
        Write-Success "PullOnly requested. Synchronization complete!"
        exit 0
    }

    # 2. Corpus Health Validation
    if (-not $SkipAudit) {
        Validate-CorpusIntegrity
    }

    # 3. Check for Changes
    $status = git status --porcelain
    if (-not $status) {
        Write-Success "Working directory is completely clean. Nothing to commit."
        exit 0
    }

    # 4. Stage Changes
    Write-Status "Staging changes..."
    git add -A

    # 5. Secret Leak Protection
    Write-Status "Scanning staged changes for accidental credentials..."
    $secretHits = @(Find-StagedSecrets)
    if ($secretHits.Count -gt 0) {
        Write-Host "==================================================" -ForegroundColor Red
        Write-Host "SECURITY HALT: Potential secrets detected in diff!" -ForegroundColor Red
        Write-Host "==================================================" -ForegroundColor Red
        foreach ($hit in $secretHits) {
            Write-Host "Pattern : $($hit.Pattern)" -ForegroundColor Yellow
            Write-Host "Snippet : $($hit.Snippet)" -ForegroundColor White
        }
        git reset
        throw "Aborting commit due to potential credential leak."
    }

    # 6. Commit Message Resolution
    $commitMsg = $Message
    if ([string]::IsNullOrWhiteSpace($commitMsg)) {
        $commitMsg = Get-AutoCommitMessage
        if ([string]::IsNullOrWhiteSpace($commitMsg)) {
            $commitMsg = "chore(corpus): update archived problems and solutions"
        }
        Write-Notice "Auto-generated commit message: $commitMsg"
    }

    # 7. Commit
    Write-Status "Committing changes..."
    git commit -m $commitMsg
    Write-Success "Commit created successfully!"

    # 8. Push
    if (-not $NoPush) {
        Write-Status "Pushing to remote origin main..."
        git push origin main
        Write-Success "Repository successfully pushed and synchronized with remote!"
    } else {
        Write-Notice "NoPush flag set. Skipping push."
    }

    Write-Success "🎉 IEEE-Xtreme-Archive sync complete!"
}
catch {
    Write-Host "Sync Error: $_" -ForegroundColor Red
    exit 1
}
