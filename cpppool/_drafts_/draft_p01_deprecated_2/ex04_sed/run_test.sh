#!/bin/bash

c1='\033[0;36m' # cyan
c2='\033[0;33m' # yellow
c3='\033[0;32m' # green
rs='\033[0m' # reset

make re

echo "Test 0. replace ${c1}\"aa\"${rs} with ${c2}\"XX\"${rs} in ${c3}random_finnish ${rs}"
./replace  testsuite/random_finnish  aa  XX
./replace  testsuite/RANDOM_FINNISH.replace  XX  aa

diff -s  testsuite/random_finnish  testsuite/RANDOM_FINNISH.REPLACE.replace
#echo

echo "test 1. replace ${c1}\"e\"${rs} with ${c2}\"(o ^ . ^)o\"${rs} in ${c3}random_portugese ${rs}"
./replace  testsuite/random_portugese  e  "(o ^ . ^)o"
./replace  testsuite/RANDOM_PORTUGESE.replace  "(o ^ . ^)o" e

diff -s  testsuite/random_portugese  testsuite/RANDOM_PORTUGESE.REPLACE.replace
#echo

echo "test 2. replace ${c1}\"do\"${rs} with ${c2}\"QWERTY\"${rs} in ${c3}random_dutch ${rs}"

./replace  testsuite/random_dutch  do  QWERTY
./replace  testsuite/RANDOM_DUTCH.replace  QWERTY do

diff -s  testsuite/random_dutch  testsuite/RANDOM_DUTCH.REPLACE.replace
#echo

echo "test 3. replace ${c1}\"se\"${rs} with ${c2}\"Distant Star\"${rs} in ${c3}random_italian ${rs}"

./replace  testsuite/random_italian  se "Distant Stars"
./replace  testsuite/RANDOM_ITALIAN.replace  "Distant Stars" se

diff -s  testsuite/random_italian  testsuite/RANDOM_ITALIAN.REPLACE.replace
#echo


echo "test 4. replace ${c1}\"te\"${rs} with ${c2}\"4242\"${rs} in ${c3}random_german ${rs}"

./replace  testsuite/random_german  te 4242
./replace  testsuite/RANDOM_german.replace  4242 te

diff -s  testsuite/random_german  testsuite/RANDOM_GERMAN.REPLACE.replace
echo
