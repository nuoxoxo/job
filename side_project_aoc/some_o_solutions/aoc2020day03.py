plan = []

with open ('3.txt', 'r') as file:
    for line in file:
        # plan.append(line.split()) # add not string but sublist!
        plan.extend(line.split())

"""Part 1"""
# Record 1
counter = x = y = 0
while x < len(plan):
    if plan[x][y] == '#':
        counter += 1
    x += 1
    if y + 3 > len(plan[0]) - 1:
        y = y + 3 - 31
    else:
        y += 3
print(counter)
rec1 = counter

"""Part 2"""
# Record 2
counter = x = y = 0
while x < len(plan):
    if plan[x][y] == '#':
        counter += 1
    x += 1
    if y + 1 > len(plan[0]) - 1:
        y = y + 1 - 31
    else:
        y += 1
print(counter)
rec2 = counter

# Record 3
counter = x = y = 0
while x < len(plan):
    if plan[x][y] == '#':
        counter += 1
    x += 1
    if y + 5 > len(plan[0]) - 1:
        y = y + 5 - 31
    else:
        y += 5
print(counter)
rec3 = counter

# Record 4
counter = x = y = 0
while x < len(plan):
    if plan[x][y] == '#':
        counter += 1
    x += 1
    if y + 7 > len(plan[0]) - 1:
        y = y + 7 - 31
    else:
        y += 7
print(counter)
rec4 = counter

# Record 5
counter = x = y = 0
while x < len(plan):
    if plan[x][y] == '#':
        counter += 1
    x += 2
    if y + 1 > len(plan[0]) - 1:
        y = y + 1 - 31
    else:
        y += 1
print(counter)
rec5 = counter

mult = rec1 * rec2 * rec3 * rec4 * rec5
print(mult)
