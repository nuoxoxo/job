fd = 1#0
path = '2219.'
file = open(path+str(fd))
Blueprint = []
count = 0
for line in file:
    segments = line.split(' Each ')
    for seg in segments:
        if 'ore robot' in seg:
            ore = int(seg.split()[3])
        if 'clay robot' in seg:
            clay = int(seg.split()[3])
        if 'obsidian robot' in seg:
            ss = seg.split()
            o1, o2 = int(ss[3]), int(ss[6])
        if 'geode robot' in seg:
            ss = seg.split()
            g1, g2 = int(ss[3]), int(ss[6])
    count += 1
    print(f'({count})', ore, clay, o1, o2, g1, g2)
    Blueprint.append([ore, clay, o1, o2, g1, g2])
for i, bp in enumerate(Blueprint): print(i, bp)
