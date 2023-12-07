from collections import defaultdict, deque

def p1(file) -> int:
    a = defaultdict(list)
    dq = deque()
    for line in file:
        l, r = line.strip().split('-')
        a[l].append(r)
        a[r].append(l)
    start = ('start', set(['start']))
    dq.append(start)
    res = 0
    while dq:
        # where we are now, which smalle caves we've seen
        pos, small = dq.popleft()
        if pos == 'end':
            res += 1
        for cave in a[pos]:
            if cave not in small:
                temp = set(small)
                if cave.lower() == cave:
                    temp.add(cave)
                dq.append((cave, temp))
    return res

def p2(file) -> int:
    a = defaultdict(list)
    dq = deque()
    for line in file:
        l, r = line.strip().split('-')
        a[l].append(r)
        a[r].append(l)
    start = ('start', set(['start']), None) #
    dq.append(start)
    res = 0
    while dq:
        pos, small, twice = dq.popleft() #
        if pos == 'end':
            res += 1
            continue #
        for cave in a[pos]:
            if cave not in small:
                temp = set(small)
                if cave.lower() == cave:
                    temp.add(cave)
                dq.append((cave, temp, twice)) #
            elif cave in small and twice is None and cave not in ['start', 'end']:
                dq.append((cave, small, cave)) #
    return res

path = '_inputs/2112.'

print('data')
print('Star 1:', p1(open(path + '0')))
print('Star 2:', p2(open(path + '0')), end='\n\n')

print('test')
print('Star 1:', end=' ')
for _ in range(1, 4): print(p1(open(path + str(_))), end=' ')
print('\nStar 2:', p2(open(path + '3')))
