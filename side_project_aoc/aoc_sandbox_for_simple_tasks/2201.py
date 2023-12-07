a = []
temp = 0
with open('_inputs_/2201.0') as file:
    for s in file:
        if s != '':
            s = s[:len(s) - 1]
        if s == '':
            a.append(temp)
            temp = 0
        else:
            temp += int(s)
a.sort()
print(a[-1])
print(sum(a[-3:]))
