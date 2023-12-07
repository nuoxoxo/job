from collections import Counter

D = {}
path = '_inputs/2114.'
file = open(path + '1')
t = ''
for line in file:
    line = line.strip()
    if '->' not in line and line != '':
        t = line.strip()
    elif '->' in line:
        a, b = line.split(' -> ')
        D[a] = b

times = 5
for _ in range(times):
    s = ''
    i = 0
    while i < len(t):
        s += t[i]
        if i + 1 < len(t):
            pair = t[i:i + 2]
            if pair in D:
                s += D[pair]
                print(s)
        i += 1
    t = s
    
C = Counter(t)
res = max(C.values()) - min(C.values())
print(res)
