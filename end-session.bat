@echo off
setlocal
powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0end-session.ps1"
if errorlevel 1 (
    echo.
    echo The end-of-session script failed.
)
pause
