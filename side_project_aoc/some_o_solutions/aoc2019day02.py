############################
##                        ##
##  copy.deepcopy is KEY  ##
##                        ##
############################

import copy

with open('2.txt') as file:
    for line in file:
        a = list(line.split(','))
        ## from csv to a list of strings 

a = list(map(int, a)) 
## list of strs converted to list of ints

# a[1] = 12
# a[2] = 2
# for x in range(0, len(a), 4):

#     if a[x] == 99:
#         break

#     if a[x] == 1: ## add
#         a[a[x + 3]] = a[a[x + 1]] + a[a[x + 2]]

#     if a[x] == 2: ## mult
#         a[a[x + 3]] = a[a[x + 1]] * a[a[x+2]]

# print(a[0])

### Abov : part 1 ###

### Belo : part 2 ###

b = copy.deepcopy(a)

for x in range(100):
    for y in range(100):
        a = copy.deepcopy(b)
        a[1] = x
        a[2] = y
        for i in range(0, len(a), 4):
            if a[i] == 99:
                if a[0] == 19690720:
                    w = 100 * x + y
                    print(i)
                break
            if a[i] == 1: 
                a[a[i + 3]] = a[a[i + 1]] + a[a[i + 2]]
            if a[i] == 2: ## mult
                a[a[i + 3]] = a[a[i + 1]] * a[a[i + 2]]
            if a[0] == 19690720:
                w = 100 * x + y
                print(w)
                break
