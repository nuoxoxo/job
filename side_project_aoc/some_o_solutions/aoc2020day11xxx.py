s = []
with open('11.txt') as file:
    for line in file:
        s.append(line.rstrip())

print(s)

for x in s:
    print(x)


"""
with open('file.txt') as f:
    my_list = list(f)
    # my_list = [x.rstrip() for x in f] # remove line breaks
"""


### frame the ferry with empty edges ###

top_bottom_row = ''
for x in range(len(s[0])):
    top_bottom_row += ' '

for x in s:
    x += ' '
    x = x[:0] + " " + x[0:]

s.insert(len(s), top_bottom_row)
s.insert(0, top_bottom_row)

for x in s:
    x += ' '
    x = x[:0] + " " + x[0:]

### done framing. now len(x) = 92 + 2 ###
### next step: define count_neighbors function

def cone(a, b): ### return the number of live neighbors
    c = 0   ### counter
    if s[a-1][b-1] in ' .L':
        c += 1
    if s[a-1][b] in ' .L':
        c += 1
    if s[a-1][b+1] in ' .L':
        c += 1
    if s[a][b-1] in ' .L':
        c += 1
    # if s[a][b] in ' .L':
    #     c += 1
    if s[a][b+1] in ' .L':
        c += 1
    if s[a+1][b-1] in ' .L':
        c += 1
    if s[a+1][b] in ' .L':
        c += 1
    if s[a+1][b+1] in ' .L':
        c += 1
    return c


# copy = s  ### maybe move the new ferry seat plan here


### make a grid


state = -1 ### trigger of iterations

while state != 0:

    state = 0

    for x in range(1, len(s) - 1):
        for y in range(1, len(s[0]) - 1):

            if s[x][y] == 'L':
                if cone(x, y) == 8:


                    temp = s[x][y]
                    temp2 = temp.replace('L', '#')
                    s[x][y] = temp2
                    # err : 'str' object does not support item assignment

                state += 1

            if s[x][y]== '#':
                if cone(x, y) >=4:


                    temp = s[x][y]
                    temp2 = temp.replace('#', 'L')
                    s[x][y] = temp2
                    

                state += 1
    if state == 0:
        break

seats = 0

for x in s:
    for y in x:
        if y == '#':
            seats += 1

# print(seats)
