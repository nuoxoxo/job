fd = 1#0
path = '2219.'
file = open(path+str(fd))
# Blueprint = []
count = 0
for line in file:
    segments = line.split(' Each ')
    temp = []
    for seg in segments:
        if 'ore robot' in seg:
            OneedsO = int(seg.split()[3])
        if 'clay robot' in seg:
            CneedsO = int(seg.split()[3])
        if 'obsidian robot' in seg:
            ss = seg.split()
            OBneedsO, OBneedsC = int(ss[3]), int(ss[6])
        if 'geode robot' in seg:
            ss = seg.split()
            GneedsO, GneedsOB = int(ss[3]), int(ss[6])
    count += 1
    print(f'({count}) ',OneedsO,CneedsO, ' ',OBneedsO,OBneedsC, ' ',GneedsO,GneedsOB)
best = 0
states = deque([0,0,0,0,1,0,0,0])
