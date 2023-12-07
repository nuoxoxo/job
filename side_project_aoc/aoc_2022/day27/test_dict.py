G = {}
D = [(-1, 0), (1, 0), (0, 1), (0, -1)]
b1 = False
b2 = True
index = 0
count = 1
for d in D:
    count *= -1
    G[(d)] = [
        index,
        (b1, count, b1 or count == 1),
        (not b2, count, not b2 and count == 1)]
    index += 1
for g in G.items():
    print(g)
