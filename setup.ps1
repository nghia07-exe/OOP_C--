[CmdletBinding()]
param()

$ErrorActionPreference = "Stop"
$workspace = $PSScriptRoot
$tools = Join-Path $workspace ".tools"
$python = Get-Command "python.exe" -ErrorAction SilentlyContinue

if ($null -eq $python) {
    throw "python.exe was not found on PATH. Install Python 3 and rerun setup.ps1."
}

$compiler = Get-Command "g++.exe" -ErrorAction SilentlyContinue
if ($null -eq $compiler) {
    throw "g++.exe was not found on PATH. Install MinGW-w64 and rerun setup.ps1."
}

Write-Host "Preparing local Python environment..."
if (-not (Test-Path -LiteralPath (Join-Path $tools "Scripts\python.exe"))) {
    & $python.Source -m venv $tools
    if ($LASTEXITCODE -ne 0) {
        throw "Could not create the local Python environment."
    }
}

$venvPython = Join-Path $tools "Scripts\python.exe"
& $venvPython -m pip install --upgrade pip clang-format
if ($LASTEXITCODE -ne 0) {
    throw "Could not install clang-format."
}

$code = Get-Command "code.cmd" -ErrorAction SilentlyContinue
if ($null -ne $code) {
    Write-Host "Installing the recommended VS Code extension..."
    & $code.Source --install-extension ms-vscode.cpptools --force
    if ($LASTEXITCODE -ne 0) {
        Write-Warning "VS Code extension installation failed; install ms-vscode.cpptools manually."
    }
} else {
    Write-Warning "code.cmd was not found. Install ms-vscode.cpptools from extensions.json manually."
}

Write-Host ""
Write-Host "Setup complete. Reopen VS Code, open a .cpp file, then press Ctrl+Shift+B."
