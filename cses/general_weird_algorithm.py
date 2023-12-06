n = int(input())
res = []
while n != 1:
    res.append(int(n))
    if n % 2 == 0:
        n /= 2
    else:
        n = n * 3 + 1
if len(res) == 0 or res[-1] != 1:
    res.append(1)
res = [str(x) for x in res]
print(' '.join(res))
