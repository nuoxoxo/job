from collections import deque, defaultdict
import sys

# path = '2216.0'
path = '2216.1'
file = open(path).read().strip()
a = [x for x in file.split('\n')]

E = defaultdict(list)
R = {}
for s in a:
    ss = s.split(';')
    valve, rate = ss[0].split()[1], int(ss[0].split('=')[1])
    to = ss[1].split('to ')[1].split()
    to.pop(0)
    for i in range(len(to)):
        if ',' in to[i]:
            to[i] = to[i][:len(to[i])-1]
    print('(parsing):', valve, rate, to)
    E[valve].append(to)
    R[valve] = rate
DP = {}
def fn(pos, valves, time):
    if time == 0:
        return 0
    key = set(pos, tuple(sorted(valves)), time)
    if key in DP:
        return DP[key]
    res = 0
    new_valve_list = [R[v] for v in valves]
    if time > 0 and pos not in valves and R[pos] > 1:
        new_valve_set = set(valves)
        new_valve_set.add(pos)
        res = max(res, sum(new_valve_list) + fn(pos, new_valves_set, time - 1))
    if time > 0:
        for e in E[pos]:
            res = max(res, sum(new_valve_list) + fn(e, valve, time - 1))
    DP[key] = res
    return res
print(fn('AA', set(), 30))
