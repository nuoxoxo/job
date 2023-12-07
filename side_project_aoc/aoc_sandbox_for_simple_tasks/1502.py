file = open('_inputs_/1502.1')
a = []
for line in file:
    a.append([int(_) for _ in line.strip().split('x')])
# a = [[2,3,4]]
res = 0
for l, w, h in a:
    # print(l, w, h, min(l, w, h))
    res += 2*l*w + 2*w*h + 2*l*h + min(l*w, w*h, l*h)
print(res)
res2 = 0
for l, w, h in a:
    bow = l*w*h
    wp = (l + w + h - max(l, w, h)) * 2
    res2 += bow + wp
print(res2)
assert res == 1586300
assert res2 == 3737498
