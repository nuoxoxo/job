pax = []

with open('4.txt', 'r') as file:
    for line in file:
        elem = line.split()
        pax.append(elem)

# recollect all substrs of one passenger
r = -1
for x in range(len(pax)):
    r += 1
    if pax[x] == []:
        for y in range(x - r + 1, x):
            pax[x - r] += pax[y]
            pax[y] = []
        r = 0

# filter empty strs
pax = list(filter(None, pax))

# ['hcl:#c0946f', 'ecl:brn', 'iyr:2017', 'eyr:2028', 'pid:161390075', 'byr:1993', 'cid:50', 'hgt:171cm']
# ['ecl:#ae12d3', 'hgt:74cm', 'cid:239', 'hcl:z', 'pid:345439730', 'iyr:1924', 'byr:2029', 'eyr:2031']

"""part 1"""

# Required fields
reqd = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid']

# list of passengers validated in part 1
pacs= []

# count = 0
for x in range(len(pax)):
    for y in range(len(reqd)):
        substring_in_pax_x = any(reqd[y] in string for string in pax[x])
        if substring_in_pax_x != True:
            break
        else:
            if y == len(reqd) - 1:
                # count += 1
                pacs.append(pax[x])
            else:
                continue
# print(count)
print(len(pacs))

"""part 2"""

# passengers converted to list of dictionaries
paks = []

for x in range(len(pacs)):
    res = dict(item.split(":") for item in pacs[x])
    paks.append(res)

# {'hcl': '#c0946f', 'ecl': 'brn', 'iyr': '2017', 'eyr': '2028', 'pid': '161390075', 'byr': '1993', 'cid': '50', 'hgt': '171cm'}
# {'ecl': '#ae12d3', 'hgt': '74cm', 'cid': '239', 'hcl': 'z', 'pid': '345439730', 'iyr': '1924', 'byr': '2029', 'eyr': '2031'}

eye = ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']
counter = 0

for line in paks:
    i = 0
    if len(line['byr']) == 4:
        i += 1
    if 1920 <= int(line['byr']) <= 2002:
        i += 1
    if len(line['iyr']) == 4:
        i += 1
    if 2010 <= int(line['iyr']) <= 2020:
        i += 1
    if len(line['eyr']) == 4:
        i += 1
    if 2020 <= int(line['eyr']) <= 2030:
        i += 1
    if 'cm' in line['hgt']:
        if 150 <= int(line['hgt'].partition('cm')[0]) <= 193:
            i += 1
    if 'in' in line['hgt']:
        if 59 <= int(line['hgt'].partition('in')[0]) <= 76:
            i += 1
    if len(line['hcl']) == 7:
        i += 1
    if line['hcl'][0] == '#':
        i += 1
    if line['ecl'] in eye:
        i += 1
    if len(line['pid']) == 9:
        i += 1
    if i == 11:
        counter += 1

print(counter)
