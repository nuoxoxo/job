file = open('_inputs_/1501.1')
line = file.read().strip()
res = 0
for c in line:
    if c == '(':
        res += 1
    else:
        res -= 1
count = 0
for i in range(len(line)):
    if count < 0:
        res2 = i
        break
    c = line[i]
    if c == '(':
        count += 1 
    else:
        count -= 1
print(res)
print(res2)
