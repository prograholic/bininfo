@echo off

if "%1" == "" goto ErrorUsage

echo "starting to build %1..." > compile_log.txt

cl /nologo /O2 /EHsc /MT /Fe%1_static_release.bin %1 >> compile_log.txt 2>&1
if NOT %ERRORLEVEL% == 0 goto ErrorCompile

cl /nologo /O2 /EHsc /MD /Fe%1_dynamic_release.bin %1 >> compile_log.txt 2>&1
if NOT %ERRORLEVEL% == 0 goto ErrorCompile


cl /nologo /Od /EHsc /MTd /Zi /Fe%1_static_debug.bin %1 >> compile_log.txt 2>&1
if NOT %ERRORLEVEL% == 0 goto ErrorCompile

cl /nologo /Od /EHsc /MDd /Zi /Fe%1_dynamic_debug.bin %1 >> compile_log.txt 2>&1
if NOT %ERRORLEVEL% == 0 goto ErrorCompile




goto Finish

:ErrorCompile
echo "compilation failed, see compile_log.txt for details"
exit /B 1


:ErrorUsage
echo "usage %0% input_file"
exit /B 2


:Finish
echo "building 4 configurations finished"
exit /B 0
