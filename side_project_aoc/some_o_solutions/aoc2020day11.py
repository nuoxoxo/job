### variation on conway's game
### deepcopy cf. advent19 day02

import copy

a = []
with open('11.txt') as f:
    for x in f.readlines():
        a.append(x.rstrip())

mapping = []
for x in a:
    tmp = []
    for y in x:
        if y == '.' or y == ' ':
            tmp.append(-1)
        if y == 'L':
            tmp.append(0)
        if y == '#':
            tmp.append(1)
    mapping.append(tmp)

### top and bottom frame

top_and_bottom_row = []
for x in mapping[0]:
    top_and_bottom_row.append(-1)

mapping.insert(0, top_and_bottom_row)
mapping.append(top_and_bottom_row)

### left and right frame

mapping[0].insert(0, -1)
mapping[len(mapping) - 1].insert(0, -1)

for x in range(1, len(mapping) - 1):
    mapping[x].insert(0, -1)

for x in range(1, len(mapping) - 1):
    mapping[x].append(-1)


#### Main quest

############################
##                        ##
##         Part 1         ##
##                        ##
############################

# # empt (L): if no occupied adjacent seats, L --> occupied
# # occu (#): if 4 or + seats occupied adjacent, # -> empty
# # flor (.): static

# def check_neighbors(x, y):
#     count_hash = 0
#     for i in range(x - 1, x + 2):
#         for j in range(y - 1, y + 2):
#             # if i != x and j != y:
#             if (i, j) != (x, y):
#                 if mapping[i][j] == 1:
#                     count_hash += 1
#     return count_hash

# maptemp = copy.deepcopy(mapping)

# counter = -1
# while True:
#     counter = 0
#     for x in range(1, len(maptemp) - 1):
#         for y in range(1, len(maptemp[x]) - 1):
#             if mapping[x][y] == 0:
#                 # print(check_neighbors(x, y))
#                 if check_neighbors(x, y) == 0:
#                     # mapping[x][y] = 1
#                     maptemp[x][y] = 1
#                     counter += 1
#             elif mapping[x][y] == 1:
#                 if check_neighbors(x, y) >= 4:
#                     # mapping[x][y] = 0
#                     maptemp[x][y] = 0
#                     counter += 1
#     if counter == 0:
#         break
#     mapping = copy.deepcopy(maptemp)


# n = 0
# for x in range(0, len(mapping)):
#     for y in range(0, len(mapping[0])):
#         if mapping[x][y] == 1:
#             n += 1
# print(n)


############################
##                        ##
##         Part 2         ##
##                        ##
############################

import time

maptemp = copy.deepcopy(mapping)

def check_visible(x, y):
    count_hash = 0
    i = 0   ### nw
    while x - i >= 0 and y - i >= 0:
        i += 1
        if mapping[x - i][y - i] == 0:
            break
        elif mapping[x - i][y - i] == 1:
            count_hash += 1
            break
    i = 0   ### north
    while x - i >= 0:
        i += 1
        if mapping[x - i][y] == 0:
            break
        elif mapping[x - i][y] == 1:
            count_hash += 1
            break
    i = 0   ### ne
    while x - i >= 0 and y + i < len(mapping[x]) - 1:
        i += 1
        if mapping[x - i][y + i] == 0:
            break
        elif mapping[x - i][y + i] == 1:
            count_hash += 1
            break
    i = 0   ### w
    while y - i >= 0:
        i += 1
        if mapping[x][y - i] == 0:
            break
        elif mapping[x][y - i] == 1:
            count_hash += 1
            break
    i = 0   ### e
    while y + i < len(mapping[x]) - 1:
        i += 1
        if mapping[x][y + i] == 0:
            break
        elif mapping[x][y + i] == 1:
            count_hash += 1
            break
    i = 0   ### sw
    while x + i < len(mapping) - 1 and y - i >= 0:
        i += 1
        if mapping[x + i][y - i] == 0:
            break
        elif mapping[x + i][y - i] == 1:
            count_hash += 1
            break
    i = 0   ### s
    while x + i < len(mapping) - 1:
        i += 1
        if mapping[x + i][y] == 0:
            break
        elif mapping[x + i][y] == 1:
            count_hash += 1
            break
    i = 0   ### se
    while x + i < len(mapping) - 1 and y + i < len(mapping[x]) - 1:
        i += 1
        if mapping[x + i][y + i] == 0:
            break
        elif mapping[x + i][y + i] == 1:
            count_hash += 1
            break
    return count_hash

tic = time.perf_counter()

counter = -1
while True:
    counter = 0
    for x in range(1, len(maptemp) - 1):
        for y in range(1, len(maptemp[x]) - 1):
            if mapping[x][y] == 0:
                if check_visible(x, y) == 0:
                    maptemp[x][y] = 1
                    counter += 1
            elif mapping[x][y] == 1:
                if check_visible(x, y) >= 5:
                    maptemp[x][y] = 0
                    counter += 1
    if counter == 0:
        break
    mapping = copy.deepcopy(maptemp)

n = 0
for x in range(0, len(mapping)):
    for y in range(0, len(mapping[0])):
        if mapping[x][y] == 1:
            n += 1
print(n)

toc = time.perf_counter()

print(toc - tic)

### elapse: 5s