# vi commands
output_file="text_output.txt"

echo    ":i"
echo    "FILE.in"
echo    "."
echo    ":wa"
#echo    ":w $output_file"
echo    ":q!"
# the expected output
echo    "FILE.in" >&2
