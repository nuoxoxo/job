from math import floor, ceil

seat = []

with open('5.txt') as file:
    for line in file:
        seat.append(line.rstrip())

#  'BFFFBBBRRR', 'BFBBBBBRRL', 'FBBBFFFLLR']

# part 1

def algo(s):
    r = [0, 127]
    c = [0, 7]
    for x in range(len(s)):
        # calc row
        if x < 6:
            if s[x] == 'F':
                r[1] = floor((r[1] - r[0])/2) + r[0]
            elif s[x] == 'B':
                r[0] = ceil((r[1] - r[0])/2) + r[0]
        if x == 6:
            if s[x] == 'F':
                row = min(r)
            elif s[x] == 'B':
                row = max(r)
        if x > 6 and x < 9:
            if s[x] == 'L':
                c[1] = floor((c[1] - c[0])/2) + c[0]
            elif s[x] == 'R':
                c[0] = ceil((c[1] - c[0])/2) + c[0]
        if x == 9:
            if s[x] == 'L':
                col = min(c)
            elif s[x] == 'R':
                col = max(c)
    seatID = row * 8 + col
    return [seatID, row, col]

high = 0
alls = [] # pt2

for x in range(len(seat)):
    w = algo(seat[x])
    if w[0] > high:
        high = w[0]
    
    alls.append(int(w[0])) # pt2
        
print(high)

# part 2
for x in range(1, 881):
    if x not in alls:
        print(x)