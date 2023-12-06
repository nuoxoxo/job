#* ******************************************** *#
#*                                              *#
#*              \\             #`#``            *#
#*              ~\o o_       0 0\               *#
#*              # \__)      (u  ); _  _         *#
#*       # \# \#  #           \  \# \# \        *#
#*      #(   . . )            (         )\      *#
#*     #  \_____#              \_______#  \     *#
#*         []  []               [[] [[]    *.   *#
#*         []] []]              [[] [[]         *#
#*                                              *#
#* ************************************ nuo *** *#

import sys
sys.setrecursionlimit(int(1e9))

n, m = [int(x) for x in input().split()]
#print(n,m)

G = [False for _ in range(n)]
E = [[] for _ in range(n)]
res = []

def DFS(i):
    G[i] = True
    for x in E[i]:
        if not G[x]:
            DFS(x)

for _ in range (m):
    a, b = [int(x) for x in input().split()]
    #print(a,b)
    a -= 1
    b -= 1
    E[a].append(b)
    E[b].append(a)

for i in range(n):
    if not G[i]:
        res.append(i)
        DFS(i)

#print(res)
print(len(res) - 1)
for i in range(1, len(res)):
    print(res[i - 1] + 1, res[i] + 1)
