## Testsuite for `$ exit [Long Long]` :dromedary_camel:

| exit $? 
| :-
| exit ' 2' 
| exit -4
| exit +8
| exit +16 
| exit 2000000
| exit 2147483648
| exit -2147483649
| exit 9223372036854775807
| exit -9223372036854775808

- "Exit code should not be capped, but ___masked___".&nbsp; cf [Here](https://github.com/symfony/symfony/issues/13996)
- "Exit codes are ___32-bit signed ints___"&nbsp; cf. [Here](https://github.com/symfony/symfony/issues/13996#issuecomment-91283407)

