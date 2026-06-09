@echo off
echo =^> Building CG-Tp1 (Windows)
mingw32-make
if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)

echo =^> Copying runtime DLLs to CG-Tp1\
copy /Y fmod\fmodex.dll CG-Tp1\

echo =^> Done. Run: CG-Tp1\CG-Tp1.exe
