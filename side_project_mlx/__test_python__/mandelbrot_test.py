#!/usr/bin/python

import sys

def z(n, c):
    if n == 0:
        return 0
    else:
        return z(n - 1, c) ** 2 + c

myC = 1
if len(sys.argv) == 2:
    myC = float(sys.argv[1])

print(f"myC = {myC}")

for n in range(11):
    print(f"z({n}) = ", end="")
    res = z(n, c = myC)
    res = int(res) if res > pow(2, 64) - 1 else res
    print(res)

