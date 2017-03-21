@echo off
cd make
"..\bin\php\php.exe" -q make.php -b "full" "Compiled By Miki Maine Amdu"
cd ..
xcopy /s "E:\arc\Zeus" "E:\Bot\SimsBot\output"
xcopy /s "E:\arc\Zeus" "E:\Bot\SimsBot\Release"

pause