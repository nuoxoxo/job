s = open('_inputs_/1503.1').read().strip()
x = 0
y = 0
S = {(x, y)}
for c in s:
    if c == '^':
        y -= 1;
    if c == 'v':
        y += 1
    if c == '<':
        x -= 1
    if c == '>':
        x += 1
    S.add((x, y))
res = len(S)
x = y = 0
xx = yy = 0
S = {(x, y)}
for i in range(0, len(s) - 1, 2):
    c, cc = s[i], s[i + 1]
    if c == '^':
        y -= 1;
    if c == 'v':
        y += 1
    if c == '<':
        x -= 1
    if c == '>':
        x += 1
    S.add((x, y))
    if cc == '^':
        yy -= 1;
    if cc == 'v':
        yy += 1
    if cc == '<':
        xx -= 1
    if cc == '>':
        xx += 1
    S.add((xx, yy))
res2 = len(S)
print(res)
print(res2)
assert res == 2565 and res2 == 2639
