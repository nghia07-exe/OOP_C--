[CmdletBinding()]
param(
    [switch]$SkipCleanup,
    [switch]$SkipPush
)

$ErrorActionPreference = "Stop"
$workspace = $PSScriptRoot
Set-Location -LiteralPath $workspace

function Confirm-Action([string]$Message) {
    $answer = Read-Host "$Message [y/N]"
    return $answer -match "^(y|yes)$"
}

function Get-GitOutput([string[]]$Arguments) {
    $output = & git @Arguments
    if ($LASTEXITCODE -ne 0) {
        throw "Git command failed: git $($Arguments -join ' ')"
    }
    return $output
}

if (-not (Get-Command git.exe -ErrorAction SilentlyContinue)) {
    throw "git.exe was not found on PATH."
}

$branch = (Get-GitOutput @("branch", "--show-current")).Trim()
if ([string]::IsNullOrWhiteSpace($branch)) {
    throw "The repository is in a detached HEAD state. Checkout a branch first."
}

$computerName = $env:COMPUTERNAME
$timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss zzz"
$commitTimestamp = Get-Date -Format "yyyy-MM-dd_HH-mm"

Write-Host "Repository: $workspace"
Write-Host "Branch: $branch"
Write-Host "Computer: $computerName"
Write-Host "Time: $timestamp"
Write-Host ""

if (-not $SkipCleanup) {
    $cleanupCandidates = @(
        Get-ChildItem -LiteralPath $workspace -Recurse -Force -File -ErrorAction SilentlyContinue |
            Where-Object {
                $_.FullName -notlike "$workspace\.git\*" -and
                $_.FullName -notlike "$workspace\.tools\*" -and
                (
                    $_.FullName -match "\\__pycache__\\" -or
                    $_.Extension -in @(".exe", ".o", ".obj") -or
                    $_.DirectoryName -match "\\build($|\\)"
                )
            }
    )

    if ($cleanupCandidates.Count -gt 0) {
        Write-Host "Cleanup candidates:"
        $cleanupCandidates | ForEach-Object { Write-Host "  $($_.FullName)" }
        if (Confirm-Action "Delete only these generated files?") {
            foreach ($file in $cleanupCandidates) {
                Remove-Item -LiteralPath $file.FullName -Force
            }
            Get-ChildItem -LiteralPath $workspace -Recurse -Directory -Force -ErrorAction SilentlyContinue |
                Where-Object {
                    $_.Name -eq "build" -and
                    $_.FullName -notlike "$workspace\.git\*" -and
                    $_.FullName -notlike "$workspace\.tools\*"
                } |
                Sort-Object FullName -Descending |
                Where-Object { @(Get-ChildItem -LiteralPath $_.FullName -Force).Count -eq 0 } |
                Remove-Item -Force
            Write-Host "Generated files cleaned."
        } else {
            Write-Host "Cleanup skipped."
        }
    } else {
        Write-Host "No generated files found to clean."
    }
}

$status = @(Get-GitOutput @("status", "--short"))
if ($status.Count -eq 0) {
    Write-Host "No changes to commit."
    exit 0
}

Write-Host ""
Write-Host "Changes to be committed:"
$status | ForEach-Object { Write-Host $_ }

if (-not (Confirm-Action "Stage all repository changes and create a commit?")) {
    Write-Host "Commit cancelled."
    exit 0
}

& git add -A
if ($LASTEXITCODE -ne 0) {
    throw "Could not stage repository changes."
}

$stagedFiles = @(Get-GitOutput @("diff", "--cached", "--name-only"))
$commitMessage = "study: session $commitTimestamp on $computerName"
$commitBody = @(
    "Computer: $computerName",
    "Finished: $timestamp",
    "Branch: $branch",
    "Changed files: $($stagedFiles.Count)"
) -join "`n"

& git commit -m $commitMessage -m $commitBody -m "Co-authored-by: Copilot <223556219+Copilot@users.noreply.github.com>"
if ($LASTEXITCODE -ne 0) {
    throw "Commit failed."
}

if (-not $SkipPush -and (Confirm-Action "Push the new commit to GitHub?")) {
    & git push
    if ($LASTEXITCODE -ne 0) {
        throw "Push failed. The commit remains safely available locally."
    }
    Write-Host "Pushed successfully."
} else {
    Write-Host "Push skipped. The commit exists locally."
}
