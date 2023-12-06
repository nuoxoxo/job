import sys

n = int(input())

L = []
for x in input().split():
    L.append(int(x))

L.sort()
if L[0] != 1:
    print(1)
    sys.exit(0)
if L[-1] != n:
    print(n)
    sys.exit(0)
for i in range(1, len(L) // 2  + 1):
    #print(L[i], L[len(L) - i])
    if (L[i] != L[i - 1] + 1):
        print(L[i - 1] + 1)
        exit(0)
    if (L[len(L) - i - 1] != L[len(L) - i] - 1):
        print(L[len(L) - i] - 1)
        exit(0)
