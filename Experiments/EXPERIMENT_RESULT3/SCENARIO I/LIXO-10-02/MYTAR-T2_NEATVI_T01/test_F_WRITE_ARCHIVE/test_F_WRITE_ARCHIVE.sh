#!/bin/sh
SUCCESFUL=0
counter_check=0
counter_pass=0
counter_failed=0
#coy vi.exe
vi_output="text_output.txt"
cd ..
cp -r -f vi test_F_WRITE_ARCHIVE
cd test_F_WRITE_ARCHIVE

echo "\nTESTING FEATURE WRITE_ARCHIVE"
testcase_copy_content(){
    counter_check=$((counter_check+1))
    file_output=$2
   # rm -f $vi_output
    #rm -f $file_output
    sh $1 /tmp/.neatvi2 2>/tmp/.neatvi1 | ./vi "$file_output" >/dev/null
    if test -f "$file_output"; then
        counter_pass=$((counter_pass+1))
        echo " $1 PASSED"
    else
        counter_failed=$((counter_failed+1))
        echo " $1 FAILED"
        SUCCESFUL=1
        #exit 1
    fi
}

file_output="TEXT.txt"
testcase_copy_content "m01.sh" "$file_output"

testcase_change_file(){
    counter_check=$((counter_check+1))
    file_oracle=$2
    file_output=$3
    
    sh $1 /tmp/.neatvi2 2>/tmp/.neatvi1 | ./vi "$file_output" >/dev/null
    if ! cmp -s "$file_oracle" "$file_output" ;  then
        counter_failed=$((counter_failed+1))
        echo " $1 FAILED"
        #diff "$2" "$file_in"
        SUCCESFUL=1
        #exit 1
    else
        counter_pass=$((counter_pass+1))
        echo " $1 PASSED"
    fi
}

file_output="TEXT.txt"
file_oracle="text_oracle_m02.txt"
testcase_change_file "m02.sh" "$file_oracle" "$file_output"

echo "RESULT: "
echo " Check: $counter_check Passed: $counter_pass Failed: $counter_failed"

exit $SUCCESFUL

