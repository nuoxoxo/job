file = open('_inputs_/1801.0')
a = []
for line in file:
    a.append(line)
res = 0
for line in a:
    res += eval(line)
res2 = 0
S = set()
i = 0
while i < len(a):
    if res2 in S:
        break
    S.add(res2)
    res2 += eval(a[i])
    i += 1
    if i == len(a):
        i = 0
print(res)
print(res2)
assert res == 529
assert res2 == 464
