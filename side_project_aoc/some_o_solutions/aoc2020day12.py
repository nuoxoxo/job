path = []

with open('12.txt', 'r') as file:
    for line in file:
        path.append(line.rstrip())

x = 0
y = 0
f = 0

facings = ['E','S','W','N']

for i in path:

    facing = facings[f]

    if i[0] == 'N' :
        y += int(i[1:])
    if i[0] == 'S':
        y -= int(i[1:])
    if i[0] == 'W':
        x -= int(i[1:])
    if i[0] == 'E':
        x += int(i[1:])

    if i[0] == "F":
        if facing == 'N':
            y += int(i[1:])
        if facing == 'S':
            y -= int(i[1:])
        if facing == 'W':
            x -= int(i[1:])
        if facing == 'E':
            x += int(i[1:])

    if i[0] == "R":
        f += int(int(i[1:]) / 90)
    if i[0] == "L":
        f -= int(int(i[1:]) / 90)

    if f > 3:
        f -= 4
    if f < 0:
        f += 4

print(abs(x)+abs(y))

#################################
########## END PART 1 ##########
###############################

x = 0
y = 0
wpx = 10
wpy = 1

for i in path:

    if i[0] == 'N' :
        wpy += int(i[1:])
    if i[0] == 'S':
        wpy -= int(i[1:])

    if i[0] == 'W':
        wpx -= int(i[1:])
    if i[0] == 'E':
        wpx += int(i[1:])

    # if i[0] == "L":
    #     if i[1:] == '90':
    #         wpx = -wpy
    #         wpy = wpx
    #     if i[1:] == '180':
    #         wpx = -wpx
    #         wpy = -wpy
    #     if i[1:] == '270':
    #         wpx = wpy
    #         wpy = -wpx

    # if i[0] == "R":
    #     if i[1:] == '90':
    #         wpx = wpy
    #         wpy = -wpx
    #     if i[1:] == '180':
    #         wpx = -wpx
    #         wpy = -wpy
    #     if i[1:] == '270':
    #         wpx = -wpy
    #         wpy = wpx

    if (i[0] == "L" and i[1:] == '90') or (i[0] == "R" and i[1:] == '270'):
            tmp = wpx
            wpx = -wpy
            wpy = tmp

    if i[1:] == '180' and (i[0] == "L" or i[0] == "R"):
            wpx = -wpx
            wpy = -wpy

    if (i[0] == "L" and i[1:] == '270') or (i[0] == "R" and i[1:] == '90'):
            tmp = wpx
            wpx = wpy
            wpy = -tmp

    if i[0] == "F":
        x += (wpx * int(i[1:]))
        y += (wpy * int(i[1:]))

print(abs(x)+abs(y))