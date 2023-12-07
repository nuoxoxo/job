from collections import Counter
from itertools import chain

file = open('6.txt', 'r')
team = [x.split() for x in file.readlines()]
# above line: .split -> list of lists ; .strip -> list of strings

r = -1
for x in range(len(team)):
    r += 1
    if team[x] == []:
        for y in range(x-r+1, x):
            team[x-r] += team[y]
            team[y] = []
        r = 0
    if x == len(team) - 1:
        for y in range(x-r+1, len(team)):
            team[x-r] += team[y]
            team[y] = []

# then the list looks like:
#n'], [], [], ['jngdhxfesqzwcptlmvb', 'tlpyhvnoxsagwmqrdzcue'], [], []]

team = list(filter(None, team))

# after filter empty strs:
#['juqckrl', 'ojlhsyfcn'], ['jngdhxfesqzwcptlmvb', 'tlpyhvnoxsagwmqrdzcue']]

""" part 1 """
n = 0
for x in range(len(team)):
    temp = (set(line) for line in team[x])
    cntr = Counter(chain.from_iterable(temp))
    lett = [chr for chr, count in cntr.items()]
    n += len(lett)
print(n)


""" part 2 """
n = 0
for x in range(len(team)):
    temp = (set(line) for line in team[x])
    cntr = Counter(chain.from_iterable(temp))
    lett = [chr for chr, count in cntr.items() if count == len(team[x])]
    n += len(lett)
print(n)
