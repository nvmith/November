@echo off
chcp 65001 >nul

set ROOT=%~dp0
set SCRIPTS=%ROOT%scripts

:menu
cls
echo ==================================
echo   📚 November Study Group Tool
echo ==================================
echo 1) 문제 추가
echo 2) 지각/결석 로그 추가
echo 3) 주차 업데이트
echo 0) 종료
echo.
set /p CH=선택하세요: 

if "%CH%"=="1" powershell -NoProfile -ExecutionPolicy Bypass -File "%SCRIPTS%\add_problem.ps1"
if "%CH%"=="2" powershell -NoProfile -ExecutionPolicy Bypass -File "%SCRIPTS%\add_log.ps1"
if "%CH%"=="3" powershell -NoProfile -ExecutionPolicy Bypass -File "%SCRIPTS%\update_week.ps1"
if "%CH%"=="0" exit /b

goto menu
