res = 0
n = 0
for i in range(1, 1000):
    if i % 15 == 0:
        res += i
        continue
    if i % 3 == 0 or i % 5 == 0:
        res += i
print(res)
