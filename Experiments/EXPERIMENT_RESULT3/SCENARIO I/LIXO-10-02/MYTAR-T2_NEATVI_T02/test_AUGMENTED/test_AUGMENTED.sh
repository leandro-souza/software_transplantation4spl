#!/bin/sh
SUCCESFUL=0
counter_check=0
counter_pass=0
counter_failed=0
vi_output="text_output.txt"
#copy vi.exe
rm -f vi
cd ..
cp -r -f vi test_AUGMENTED
cd test_AUGMENTED

echo "\nTESTING FEATURE AUGMENTED"
testcase_augmented(){
    rm -f $vi_output
    file_oracle=$2
    file_in=$3
    counter_check=$((counter_check+1))
    rm -f $vi_output
    rm -f /tmp/.neatvi[12]
    sh $1 /tmp/.neatvi2 2>/tmp/.neatvi1 | ./vi "$3" >/dev/null
    
    if ! cmp -s "$2" "$vi_output" ;  then
        counter_failed=$((counter_failed+1))
        echo " $1 FAILED"
        SUCCESFUL=1
        #exit 1
    else
        counter_pass=$((counter_pass+1))
        echo " $1 PASSED"
    fi
}

file_in="TEXTO_ORIGINAL.txt"
file_oracle="text_oracle_c01.txt"
testcase_augmented "c01.sh" "$file_oracle" "$file_in"


file_oracle="text_oracle_c02.txt"
testcase_augmented "c02.sh" "$file_oracle" "$file_in"

echo "RESULT: "
echo " Checks: $counter_check Passed: $counter_pass Failed: $counter_failed"

exit $SUCCESFUL
echo $couter_check
