import math

a = []

with open('1.txt') as file:
    for line in file:
        a.append(int(line.rstrip()))

# part 1
w = 0
for x in a:
    w += math.floor(x / 3 - 2)
print(w)

# part 2
n = 0
for x in a:
    w = 0
    while math.floor(x / 3 - 2) > 0:
        x = math.floor(x / 3 - 2)
        w += x
    n += w
print(n)
