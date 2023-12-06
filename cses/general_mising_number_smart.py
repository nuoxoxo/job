import sys

n = int(input())
L = 0
for x in input().split():
    L += int(x)
print(int(n * (n + 1) // 2 - L))
