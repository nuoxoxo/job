from collections import Counter

a = []

with open('10.txt') as file:
    for line in file:
        a.append(int(line.rstrip()))

#####################
###### Part 1 ######
###################

path = a # mapping

def p1(n):
    # count one-jolt and three-jolt
    c1 = 1
    c3 = 1
    x = 1 # x is jolt
    while True:
        if x == max(n):
            break
        elif x + 1 in path:
            x += 1
            c1 += 1
        elif x + 2 in path:
            x +=2
        elif x + 3 in path:
            x += 3
            c3 += 1

    return c1 * c3

print(p1(a))

#####################
###### Part 2 ######
###################

def p2(n):

    n.sort()
    n.append(max(n) + 3)
    Counter = {0:1}

    for x in n:
        Counter[x] = Counter.get(x - 3, 0) + Counter.get(x - 2, 0) + Counter.get(x - 1, 0)

    return Counter
    ###### return Counter[max[n]]
    ###### somehow max[n] uses a loop thus unable to parse

# print(list(p2(a)).index(max(n)))

print(p2(a))
### ... see it from console


