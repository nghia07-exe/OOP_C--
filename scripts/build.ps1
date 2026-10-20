[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [string]$SourceFile,

    [switch]$Run
)

$ErrorActionPreference = "Stop"
$workspace = Split-Path -Parent $PSScriptRoot
$source = [System.IO.Path]::GetFullPath($SourceFile)

if (-not (Test-Path -LiteralPath $source -PathType Leaf)) {
    throw "Source file not found: $source"
}

if ([System.IO.Path]::GetExtension($source) -ne ".cpp") {
    throw "The active file must be a .cpp file."
}

$exerciseDirectory = Split-Path -Parent $source
$cppFiles = @(
    Get-ChildItem -LiteralPath $exerciseDirectory -Filter "*.cpp" -File |
        Sort-Object Name
)

if ($cppFiles.Count -eq 0) {
    throw "No .cpp files found in: $exerciseDirectory"
}

$compiler = Get-Command "g++.exe" -ErrorAction SilentlyContinue
if ($null -eq $compiler) {
    throw "g++.exe was not found on PATH. Install MinGW-w64 or update PATH."
}

$buildDirectory = Join-Path $exerciseDirectory "build"
$output = Join-Path $buildDirectory "program.exe"
New-Item -ItemType Directory -Path $buildDirectory -Force | Out-Null

Write-Host "Building $($cppFiles.Count) source file(s) from $exerciseDirectory"
& $compiler.Source `
    "-std=c++17" `
    "-Wall" `
    "-Wextra" `
    "-pedantic" `
    "-g" `
    @($cppFiles.FullName) `
    "-o" `
    $output

if ($LASTEXITCODE -ne 0) {
    throw "Compilation failed with exit code $LASTEXITCODE."
}

Write-Host "Built: $output"

if ($Run) {
    $inputFile = Join-Path $workspace "input.txt"
    if (-not (Test-Path -LiteralPath $inputFile -PathType Leaf)) {
        throw "Input file not found: $inputFile"
    }

    Write-Host "Running with input: $inputFile"
    $command = '"' + $output + '" < "' + $inputFile + '"'
    & $env:ComSpec "/d" "/c" $command
    if ($LASTEXITCODE -ne 0) {
        throw "Program exited with code $LASTEXITCODE."
    }
}
