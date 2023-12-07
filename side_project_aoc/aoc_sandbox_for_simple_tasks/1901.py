file = open('_inputs_/1901.0')
res = 0
res2 = 0
for s in file:
    n = int(s)
    res += n // 3 - 2
    temp = n // 3 - 2
    while temp > 0:
        res2 += temp
        temp = temp // 3 - 2
print(res)
print(res2)
