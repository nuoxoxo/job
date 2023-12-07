a = [1, 2]
r = 2
while True:
    n = a[-1] + a[-2]
    if n > 4000000:
        break
    if (n & 1) == 0:
        r += n
    a.append(n)
print(r)
