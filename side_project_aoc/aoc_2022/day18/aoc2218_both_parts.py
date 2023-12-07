path = '2218.0'
# path = '2218.1'

file = open(path).read().strip()
a = [x for x in file.split('\n')]
# print(a)

all_cubes = []
outmost = -1 # p2
for l in a:
    print(l)
    tup = tuple(int(_) for _ in l.split(','))
    # all_cubes.append(tuple(int(_) for _ in l.split(',')))
    all_cubes.append(tup)
    for t in tup:
        if outmost < t:
            outmost = t # p2
# print(all_cubes)
print('\noutmost corner:', outmost, end='\n\n')

D = [
    (1, 0, 0),
    (0, 1, 0),
    (0, 0, 1),
    (-1,0, 0),
    (0,-1, 0),
    (0, 0,-1),
    ]

# res = 0
cube_face = []
for cube in all_cubes:
    for face in D:
        L = []
        for i in range(3): L.append(cube[i] + face[i])
        if tuple(int(_) for _ in L) not in all_cubes:
            cube_face.append((cube, face))

res = len(cube_face)

# part 2
## (no bfs or floodfill, just brute force)

outside_cubes = set()
outside_faces = []
outside_faces_size = set()
count = 0

while True:
    count += 1
    size = len(outside_faces)
    print(f'{size}\toutside faces (iteration {count})')
    if size != 0 and size in outside_faces_size:
        res2 = size
        print(f'{res2}\t{outside_faces_size}', end='\n\n')
        break
    else:
        outside_faces_size.add(size)
    for cf in cube_face:
        if cf in outside_faces:
            continue
        seen = set()
        cube, face = cf
        for dist in range(1, outmost):
            # print(dist)
            x = cube[0] + face[0] * dist
            y = cube[1] + face[1] * dist
            z = cube[2] + face[2] * dist
            new_cube = (x, y, z)
            seen.add(new_cube)
            if new_cube in all_cubes:
                break
            if new_cube in outside_cubes:
                outside_cubes |= seen
                outside_faces.append(cf)
                break
            ok = False
            for c in range(3):
                if new_cube[c] < 0 or new_cube[c] > 21:
                    outside_cubes |= seen
                    outside_faces.append(cf)
                    ok = True
                    break
            if ok:
                break

print('Star 1:', res)
print('Star *:', res2)

