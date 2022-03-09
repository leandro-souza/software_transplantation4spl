#!/bin/bash
SUCCESFUL=0
cd ..
cp -r -f *.c test_F_DIR
cp -r -f *.h test_F_DIR
cd test_F_DIR
rm -r -f *.o
make > /dev/null 2>&1
echo "\nTESTING FEATURE DIR_INIT"
if ./Individual.x > /dev/null; then
    output=$(./Individual.x)
    echo "RESULT: $output"
    #PASSED
else
    output=$(./Individual.x)
    echo "RESULT: $output"
    #FAILED
    #./Individual.x
    SUCCESFUL=1
fi
#echo "\nALL tests finished!" >> $test_output_file
rm -r -f *.h
rm -r -f *.c
rm -r -f *.o
exit $SUCCESFUL

