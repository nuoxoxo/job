a = []
with open('test') as file:
    for s in file:
        a.append(s.strip())

col = len(a[0])
aa = [''] * col

#   part 1

for i in range(len(a)):
    s = a[i]
    for j in range(col):
        aa[j] += s[j]

g = ''
e = ''

for line in aa:
    c = max(set(line), key=line.count)
    g += c
    c = min(set(line), key=line.count)
    e += c
res = int(g, 2) * int(e, 2)
print("Star 1:", res)

#   part 2

oxy = []
co2 = []

for l in a:
    oxy.append(int(l, 2))
    co2.append(int(l, 2))
for l in a:
    c = max(set(l), key=l.count)
    cc = '1' if c == '0' else '0'
