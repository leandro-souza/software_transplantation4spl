#!/bin/sh
SUCCESFUL=0
test_output_file=$1
rm -f $test_output_file

#EXECUTING REGRESSION TEST CASES
echo "EXECUTING REGRESSION TEST CASES" >> $test_output_file

if result=$(./test.sh) > /dev/null; then
    SUCCESFUL=1
fi
#print result in $test_output_file
echo "$result" >> $test_output_file
#show result
while IFS= read -r line; do
    echo "$line"
done <<< "$result"

echo "\nEXECUTING HOST POST-OPERATIVE TEST CASES" >> $test_output_file
#TESTING FEATURE AUGMENTED
cd test_AUGMENTED
if result=$(./test_AUGMENTED.sh) > /dev/null; then
    SUCCESFUL=1
fi
cd ..
#print result in $test_output_file
echo "$result" >> $test_output_file
#show result
while IFS= read -r line; do
    echo "$line"
done <<< "$result"

#TESTING FEATURE WRITE_ARCHIVE
cd test_F_WRITE_ARCHIVE
if result=$(./test_F_WRITE_ARCHIVE.sh) > /dev/null; then
    SUCCESFUL=1
fi
cd ..
#print result in $test_output_file
echo "$result" >> $test_output_file
#show result
while IFS= read -r line; do
    echo "$line"
done <<< "$result"

#TESTING FEATURE DIR_INIT
cd test_F_DIR
if result=$(./test_dir_init.sh) > /dev/null; then
    SUCCESFUL=1
fi
cd ..
#print result in $test_output_file
echo "$result" >> $test_output_file
#show result
while IFS= read -r line; do
    echo "$line"
done <<< "$result"

if [ $SUCCESFUL == 0 ]; then
 echo "All test passed!!"
else
 echo "One or more tests filed!"
fi

exit $SUCCESFUL
