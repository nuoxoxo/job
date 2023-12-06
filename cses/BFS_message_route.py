#* ************************************************************************** *#
#*                                                                            *#
#*                            \\             #`#``                            *#
#*                            ~\o o_       0 0\                               *#
#*                            # \__)      (u  ); _  _                         *#
#*                     # \# \#  #           \  \# \# \                        *#
#*                    #(   . . )            (         )\                      *#
#*                   #  \_____#              \_______#  \                     *#
#*                       []  []               [[] [[]    *.                   *#
#*                       []] []]              [[] [[]                         *#
#*                                                                            *#
#* ****************************************************************** nuo *** *#

import sys

n, m = [int(x) for x in input().split()]

E = [[] for _ in range(n)]

for _ in range(m):
    a, b = [int(x) for x in input().split()]
    a -= 1
    b -= 1
    E[a].append(b)
    E[b].append(a)

Parent = [None for _ in range(n)]
Seen = [False for _ in range(n)]
Seen[0] = True
Q = [0]

while Q:
    #print(Parent)
    x = Q.pop(0)
    if x == n - 1:
        route = [x]
        while Parent[x] is not None:
            x = Parent[x]
            route.append(x)
        route = [str(x + 1) for x in reversed(route)]
        print(len(route))
        print(' '.join(route))
        sys.exit(0)

    for i in E[x]:
        if Seen[i]:
            continue
        Seen[i] = True
        Parent[i] = x
        Q.append(i)

print('IMPOSSIBLE')
