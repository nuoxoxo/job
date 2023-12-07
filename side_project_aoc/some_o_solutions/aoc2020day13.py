### Part 1

## access the earliest timestamp
with open('13.txt') as f:
    stamp = int(f.readline().rstrip())

## list all bus IDs
with open('13.txt') as f:
    next(f)
    s = f.readline().split(',')

busid = list(s)

print(stamp)
# print(busid)

mindf = 0   ### next: find min diff

for x in busid:
    if x != 'x':
        n = int(x)
        tmp = n
        while n < stamp:
            n += tmp

        diff = n - stamp
        # print(diff)

        if mindf == 0:
            mindf = diff
        elif diff < mindf:
            mindf = diff
            thatbus = tmp

print(mindf * thatbus)

### Part 2

startingpoint = stamp
# # startingpoint = 100000014137010

# while True:
#     if startingpoint % int(busid[0]) != 0:
#         startingpoint += 1
#     else:
#         break
# print(startingpoint)
# i = 1
# while i != len(busid):
#     if busid[i] != 'x':
#         if int(busid[i]) - startingpoint != x:
#             startingpoint += int(busid[0])
#             print(startingpoint)
#             i = 1
#     i += 1
# print(startingpoint)

### brute force failed

while True:
    if startingpoint % int(busid[0]) != 0:
        startingpoint += 1
    else:
        break

#print(startingpoint)
### get 1st legal timestamp

space = int(busid[0])

i = 1
while i != len(busid):
    if busid[i] != 'x':
        while (startingpoint + i) % int(busid[i]) != 0:
            startingpoint += space
            print(startingpoint)
            ## i = 1
        space *= int(busid[i])
        ### same: proj euler no.5
    i += 1

print(startingpoint)

