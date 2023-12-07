### game of life

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
# empt (L): if no occupied adjacent seats, L --> occupied
# occu (#): if 4 or + seats occupied adjacent, # -> empty
# flor (.): static

def check_neighbors(x, y):
    count_hash = 0
    for i in range(x - 1, x + 2):
        for j in range(y - 1, y + 2):
            # if i != x and j != y:

            ### Crucial line
            if (i, j) != (x, y):
                if mapping[i][j] == 1:
                    count_hash += 1
    return count_hash

# empt (L): if no occupied adjacent seats, L --> occupied
# occu (#): if 4 or + seats occupied adjacent, # -> empty
# flor (.): static

# maptemp = mapping

### why above line causes 2 lists change at the same time
### Answer:
### With arr1 = arr2, you don't actually have two lists
### The assignment copies the reference to the list
### not the actual list
### so both arr1 and arr2 refer to a same list after assignment.
### Solution:
### arr2 = arr1.copy()
### ... even copy.copy() does't work
### only deepcopy works

import copy

maptemp = copy.deepcopy(mapping)

counter = -1
while True:
    counter = 0
    # for x in mapping:
    #     print(x)
    # print('\n')
    for x in range(1, len(maptemp) - 1, 1):
        for y in range(1, len(maptemp[x]) - 1, 1):
            if mapping[x][y] == 0:
                # print(check_neighbors(x, y))
                if check_neighbors(x, y) == 0:
                    # mapping[x][y] = 1
                    maptemp[x][y] = 1
                    counter += 1
            elif mapping[x][y] == 1:
                if check_neighbors(x, y) >= 4:
                    # mapping[x][y] = 0
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
### too hi: 7251, 3598
### 2321