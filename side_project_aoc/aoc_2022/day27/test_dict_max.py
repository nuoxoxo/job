G = {}
D = [
        (-1, 0), (1, 0), (0, 1), (0, -1),
        (0, 0), (-1, -1), (1, 1), (1, -1), (-1, 1)
    ]

rounds = 10
coef = 2
for d in D:
    if d in G:
        G[d] += 1 + coef
    else:
        G[d] = 1 + coef
    coef -= 1
    if coef == -1:
        coef = 3

for k, v in G.items(): print(f'{v} key:{k}')

best = max(G, key=G.get)

print('best:', best)
