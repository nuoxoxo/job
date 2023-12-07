pos = 0
depth = 0

pos_2 = 0
depth_2 = 0

aim = 0

for line in open('../input/2102.0'):
    s, x = line.split()
    x = int(x)
    if s == 'forward':
        pos += x
        pos_2 += x
        depth_2 += aim * x
    else:
        if s == 'up':
            x = -x
        depth += x
        aim += x
print('Star 1:', depth * pos)
print('Star 1:', depth_2 * pos_2)
