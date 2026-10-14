@echo off
setlocal enabledelayedexpansion

:: Hello, if ur sus about this code plz Gemini se puch lo ke safe hai k nahi
:: Kyu k maine bhi usi se likhwaya 😭
:: Its meant to provide ease of access, if uve made any mistake along the way it'll try to fix it.

set "SFML_FINAL="
set "MINGW_FINAL="
set "SFML_ROOT="

set "SFML_CANDIDATES[0]=C:\SFML"
set "SFML_CANDIDATES[1]=C:\SFML-3.1"
set "SFML_CANDIDATES[2]=C:\SFML-3.1.0"

for /L %%i in (0,1,2) do (
    if not defined SFML_ROOT (
        set "BASE_DIR=!SFML_CANDIDATES[%%i]!"
        if exist "!BASE_DIR!" (
            if exist "!BASE_DIR!\bin" (
                set "SFML_ROOT=!BASE_DIR!"
            ) else (
                for /d %%d in ("!BASE_DIR!\*") do (
                    if exist "%%d\bin" if not defined SFML_ROOT (
                        set "SFML_ROOT=%%d"
                    )
                )
            )
        )
    )
)

if defined SFML_ROOT (
    set "SFML_FINAL=!SFML_ROOT!\bin"
    if /i not "!SFML_ROOT!"=="C:\SFML" (
        if exist "C:\SFML" rmdir "C:\SFML" 2>nul
        if not exist "C:\SFML" (
            mklink /j "C:\SFML" "!SFML_ROOT!" >nul
            if !errorlevel! neq 0 (
                echo Direct link creation failed. Attempting to rename...
                ren "!SFML_ROOT!" "SFML" 2>nul
                if exist "C:\SFML" (
                    set "SFML_ROOT=C:\SFML"
                    set "SFML_FINAL=C:\SFML\bin"
                )
            )
        )
    )
)

set "MINGW_CANDIDATES[0]=C:\mingw64"
set "MINGW_CANDIDATES[1]=C:\winlibs-x86_64-posix-seh-gcc-14.2.0-mingw-w64ucrt-12.0.0-r2"
set "MINGW_CANDIDATES[2]=C:\SFML-3.1.0-windows-gcc-14.2.0-mingw-64-bit.zip"

for /L %%i in (0,1,2) do (
    if not defined MINGW_FINAL (
        set "BASE_DIR=!MINGW_CANDIDATES[%%i]!"
        if exist "!BASE_DIR!" (
            if exist "!BASE_DIR!\bin" (
                set "MINGW_FINAL=!BASE_DIR!\bin"
            ) else (
                for /d %%d in ("!BASE_DIR!\*") do (
                    if exist "%%d\bin" if not defined MINGW_FINAL (
                        set "MINGW_FINAL=%%d\bin"
                    )
                )
            )
        )
    )
)

if not defined SFML_FINAL (
    echo SFML bin directory could not be found.
    goto end
)
if not defined MINGW_FINAL (
    echo MinGW bin directory could not be found.
    goto end
)

for /f "tokens=2*" %%A in ('reg query "HKCU\Environment" /v PATH 2^>nul') do set "USERPATH=%%B"
if not defined USERPATH set "USERPATH="

echo %USERPATH% | find /i "%SFML_FINAL%" >nul
if %errorlevel% neq 0 (
    if "%USERPATH%"=="" (
        set "USERPATH=%SFML_FINAL%"
    ) else (
        set "USERPATH=%USERPATH%;%SFML_FINAL%"
    )
    echo Adding %SFML_FINAL% to User PATH...
) else (
    echo %SFML_FINAL% is already in User PATH.
)

echo %USERPATH% | find /i "%MINGW_FINAL%" >nul
if %errorlevel% neq 0 (
    if "%USERPATH%"=="" (
        set "USERPATH=%MINGW_FINAL%"
    ) else (
        set "USERPATH=%USERPATH%;%MINGW_FINAL%"
    )
    echo Adding %MINGW_FINAL% to User PATH...
) else (
    echo %MINGW_FINAL% is already in User PATH.
)

setx PATH "%USERPATH%" >nul

if %errorlevel% equ 0 (
    echo.
    echo Environment variables updated successfully!
    echo SFML Target Linked to: C:\SFML
    echo MinGW Bin Found At: %MINGW_FINAL%
    echo Please restart your command prompt or IDE for changes to take effect.
) else (
    echo.
    echo Error: Failed to update environment variables.
)

:end
pause
