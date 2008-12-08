REM @ECHO OFF
echo CppGenerator run... > %TEMP%\CppGenerator.log
date /T >> %TEMP%\CppGenerator.log
time /T >> %TEMP%\CppGenerator.log

echo Called with 'CppGenerator.bat %1 %2 %3' >> %TEMP%\CppGenerator.log
echo Running 'CppGenerator.exe %1 %TEMP%\%~n2.c' >> %TEMP%\CppGenerator.log
C:\Programme\Astade\CppGenerator.exe %1 %TEMP%\%~n2.c
if not errorlevel 0 goto end

:cppfile
echo diff -I ".*@date.*UTC.*" -N %TEMP%\%~n2.cpp %~d2%~p2%~n2.cpp >> %TEMP%\CppGenerator.log
diff -I ".*@date.*UTC.*" -N %TEMP%\%~n2.cpp %~d2%~p2%~n2.cpp >> %TEMP%\CppGenerator.log
if errorlevel 0 goto hfile
echo copy /y %TEMP%\%~n2.cpp %~d2%~p2%~n2.cpp >> %TEMP%\CppGenerator.log
copy /y %TEMP%\%~n2.cpp %~d2%~p2%~n2.cpp

:hfile
echo diff -I ".*@date.*UTC.*" -N %TEMP%\%~n2.h %~d2%~p2%~n2.h  >> %TEMP%\CppGenerator.log
diff -I ".*@date.*UTC.*" -N %TEMP%\%~n2.h %~d2%~p2%~n2.h  >> %TEMP%\CppGenerator.log
if errorlevel 0 goto end
echo copy /y %TEMP%\%~n2.h %~d2%~p2%~n2.h >> %TEMP%\CppGenerator.log
copy /y %TEMP%\%~n2.h %~d2%~p2%~n2.h


:end