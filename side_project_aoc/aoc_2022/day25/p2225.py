

total = 0

for line in open('2225.1').read().splitlines():
    line = line[::-1]
    print(line)
    coef = 1
    for c in line:
        total += ("=-012".index(c) - 2) * coef
        coef *= 5

print(total)

output = ""

while total:
    rem = total % 5
    total //= 5
    
    if rem > 2:
        output = '=-'[(rem-3)] + output
        total += 1
    else:
        output = str(rem) + output


print(output)
