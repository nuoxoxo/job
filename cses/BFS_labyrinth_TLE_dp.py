from collections import deque
import sys
#import time

#head = time.time()

dr = [-1, 0, 1, 0]
dc = [ 0, 1, 0,-1]
Q = deque()
G = []

R, C = [int(x) for x in input().split()]
Seen = [[False for _ in range(C)] for _ in range(R)]
#Seen = set()
Step = [[None for _ in range(C)] for _ in range(R)]

for _ in range(R):
    G.append(input())
for r in range(R):
    for c in range(C):
        if G[r][c] == 'A':
            start = (r, c)
        if G[r][c] == 'B':
            end = (r, c)

Q.append((start, 0))
while Q:
    ((r, c), d) = Q.popleft()
    #print((r,c),d)
    #if (r, c) in Seen:
    if not Seen[r][c]:
        if (r, c) == end:
            print('YES')
            print(d)
            Path = []
            while Step[r][c] != None:
                i = Step[r][c]
                Path.append(['U', 'R', 'D', 'L'][i])
                r += dr[(i + 2) % 4]
                c += dc[(i + 2) % 4]
            Path = ''.join(list(reversed(Path)))
            print(Path)
            #tail = time.time()
            #print(tail - head);
            sys.exit(0)
        Seen[r][c] = True
        #Seen.add((r, c))
        #print(Seen)
        for i in range(4):
            rr = r + dr[i]
            cc = c + dc[i]
            if 0 <= rr < R and 0 <= cc < C and \
            G[rr][cc] != '#' and not Seen[rr][cc]:
            #G[rr][cc] != '#' and (r, c) not in Seen:
                Step[rr][cc] = i
                Q.append(((rr,cc), d + 1))
#tail = time.time()
#print(tail - head)
print('NO')
