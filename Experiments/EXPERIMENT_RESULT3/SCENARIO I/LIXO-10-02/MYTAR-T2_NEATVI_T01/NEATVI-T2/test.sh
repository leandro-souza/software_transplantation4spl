#!/bin/sh
SUCCESFUL=0
counter_check=0
counter_pass=0
counter_failed=0
# testcase vi_options test.sh
testcase() {
    counter_check=$((counter_check+1))
    rm -f /tmp/.neatvi[12]
    printf "$x: "
    sh $2 /tmp/.neatvi2 2>/tmp/.neatvi1 | ./vi $1 >/dev/null
    if ! cmp -s /tmp/.neatvi[12]; then
        counter_failed=$((counter_failed+1))
        printf "FAILED\n"
        #diff -u /tmp/.neatvi[12]
        SUCCESFUL=1
        #exit 1
    else
        counter_pass=$((counter_pass+1))
        printf "PASSED\n"
    fi

}

for x in test/e??.sh; do
    testcase "-s -e" "$x"
done
for x in test/v??.sh; do
    testcase "-v" "$x"
done
echo "RESULT: "
echo " Checks: $counter_check Passed: $counter_pass Failed: $counter_failed"

exit  SUCCESFUL
