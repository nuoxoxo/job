## 
```coffee
➜  xcq git:(mono) ➜ ulimit -aH
-t: cpu time (seconds)              unlimited
-f: file size (blocks)              unlimited
-d: data seg size (kbytes)          unlimited
-s: stack size (kbytes)             65532
-c: core file size (blocks)         unlimited
-v: address space (kbytes)          unlimited
-l: locked-in-memory size (kbytes)  unlimited
-u: processes                       2088
-n: file descriptors                unlimited

➜  xcq git:(mono) ➜ ulimit -n 
256
```

- "a simple fix for "too many files open" (mos) is `ulimit - n` ... the default is 256"&nbsp; cf. [Here](https://discussions.apple.com/thread/251000125)

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

- "Exit code should not be capped, but ___masked___"&nbsp; cf. [Here](https://github.com/symfony/symfony/issues/13996)
- "Exit codes are ___32-bit signed ints___"&nbsp; cf. [Here](https://github.com/symfony/symfony/issues/13996#issuecomment-91283407)

