# vi commands
file_output="TEXT.txt"
echo    ":i"
echo    "\nFILE.in"
echo    "."
echo    ":wa"
echo    ":w $file_output"
echo    ":q"
# the expected output
echo    "FILE.in" >&2
