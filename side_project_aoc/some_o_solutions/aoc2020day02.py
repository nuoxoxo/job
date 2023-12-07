policy = []

with open ('day2.txt', 'r') as file:
    for line in file:
        item = line.split()
        policy.append(item)

# part 1
counter = 0
for x in range(len(policy)):
    mini = int(policy[x][0].partition('-')[0])
    maxi = int(policy[x][0].partition('-')[2])
    char = policy[x][1].partition(':')[0]
    count = policy[x][2].count(char)
    if count >= mini and count <= maxi:
        counter += 1
print(counter)

# part 2
counter = 0
for x in range(len(policy)):
    left = int(policy[x][0].partition('-')[0]) - 1
    right = int(policy[x][0].partition('-')[2]) - 1
    char = policy[x][1].partition(':')[0]
    if char in policy[x][2][left] and char in policy[x][2][right]:
        continue
    elif char in policy[x][2][left] or char in policy[x][2][right]:
        counter += 1
print(counter)
