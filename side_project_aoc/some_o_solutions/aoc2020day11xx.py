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

top_and_bottom_row = []
for x in mapping[0]:
    top_and_bottom_row.append(-1)

mapping.insert(0, top_and_bottom_row)
mapping.append(top_and_bottom_row)

### top and bottom framing done

# for x in mapping:
#     print(x)

mapping[0].insert(0, -1)
mapping[len(mapping) - 1].insert(0, -1)

for x in range(1, len(mapping) - 1):
    mapping[x].insert(0, -1)

for x in range(1, len(mapping) - 1):
    mapping[x].append(-1)




for x in range(0, len(mapping)):
    for y in range(0, len(mapping[x])):
        if mapping[x][y] == 0:
            mapping[x][y] = 1

# for x in mapping:
#     print(x)

#### Main quest
# empt (L): if no occupied adjacent seats, L --> occupied
# occu (#): if 4 or + seats occupied adjacent, # -> empty
# flor (.): static


# def check_neighbors(i, j):
#     count_hash = 0
#     for x in range(i - 1, i + 2):
#         for y in range(j - 1, j + 2):
#             if x != i and y != j:
#                 if a[x][y] == '#':
#                     count_hash += 1
#     return count_hash

def check_neighbors(i, j):
    count_hash = 0
    for x in range(i - 1, i + 2):
        for y in range(j - 1, j + 2):
            if x != i and y != j:
                if mapping[x][y] == 1:
                    count_hash += 1

    return count_hash

# empt (L): if no occupied adjacent seats, L --> occupied
# occu (#): if 4 or + seats occupied adjacent, # -> empty
# flor (.): static

counter = -1
while counter != 0:
    counter = 0
    for x in range(1, len(mapping) - 1):
        for y in range(1, len(mapping[x]) - 1):
            if mapping[x][y] == 0:
                if check_neighbors(x, y) == 0:
                    mapping[x][y] = 1
                    counter += 1
            elif mapping[x][y] == 1:
                if check_neighbors(x, y) >= 4:
                    mapping[x][y] = 0
                    counter += 1
    for x in mapping:
        print(x)
    print(counter)

##################################
####### maybe can't use a loop
####### because looping has sequence/order
####### in game of life changes are simultaneous
##################################

### problem:
### str is immutable (('str' object does not support item assignment))
### solution:
### create an array of int, L:0, #:1, .:-1

# mapping = []
# for x in a:
#     tmp = []
#     for y in a:
#         if y == '.' or y == ' ':
#             tmp.append(-1)
#         elif y == 'L':
#             tmp.append(0)
#         elif y == '#':
#             tmp.append(1)
#     mapping.append(tmp)
# print(len(mapping[0]))
# print(len(mapping))
# print(mapping)


# print(len(mapping))
# for x in mapping:
#     print(len(x))

n = 0
for x in range(0, len(mapping)):
    for y in range(0, len(mapping[0])):
        if mapping[x][y] == 1:
            n += 1
print(n)
### too hi: 7251, 3598