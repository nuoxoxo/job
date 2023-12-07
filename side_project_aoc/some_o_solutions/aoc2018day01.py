a = []

with open('18day01.txt') as f:
    for line in f:
        a.append(line.rstrip())

part1 = 0

for x in a:
    if x[0] == '-':
        s = ''
        for y in range(1, len(x)):
            s += x[y]
        part1 -= int(s)
    else:
        s = ''
        for y in range(1, len(x)):
            s += x[y]
        part1 += int(s)


import time

temp = 0
part2 = 0
b = []
i = 0
tic = time.perf_counter()

while i != len(a):
# for i in range(0, len(a)):
    if a[i][0] == '-':
        s = ''
        for j in range(1, len(a[i])):
            s += a[i][j]
        temp -= int(s)
        if temp in b:
            part2 = temp
            break
        else:
            b.append(temp)
    else:
        s = ''
        for j in range(1, len(a[i])):
            s += a[i][j]
        temp += int(s)
        if temp in b:
            part2 = temp
            break
        else:
            b.append(temp)
    if i == len(a) - 1:
        i = 0
    else:
        i += 1
toc = time.perf_counter()
print(toc-tic)  # 189.8s

print(part1)
print(part2)
# print(temp)