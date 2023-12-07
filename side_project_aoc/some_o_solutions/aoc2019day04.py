### Your puzzle input is 171309 - 643603 ###

start = 171309
end = 643603 

##start = 177777
##end = 600000

arr1 = []

for x in range(start, end, 1):
    s = str(x)
    adja = 0
    decr = 0
    for i in range(0, len(s) - 1, 1):
        if s[i] == s[i + 1]:
            ##print(s) ## checked
            adja = 1    ### at least a double


    ##      wonder why it fails

    ##for i in range(0, len(s) - 1, 1):
        ##for j in range(i, len(s), 1):
            ##if int(s[i]) < int(s[j]):
                ##decr = 1


    for i in range(0, len(s) - 1, 1):
        if int(s[i + 1]) < int(s[i]):
            decr += 1

    if adja > 0 and decr == 0:
        if x not in arr1:
            arr1.append(x)

print(len(arr1))

# lo: 544 454
# hi: 2856

###########################
####### End Part 1 ######
#######################
###### Part 2 #######
###################

arr2 = []

for x in range(start, end, 1):
    s = str(x)
    
    aj = 0
    dc = 0

    for i in range(0, 5, 1):
        ##for j in range(0, 6, 1):
        if s[i] == s[i + 1]:
            if i <= 3:
                if s[i + 1] != s[i + 2]:
                    if i >= 1:
                        if s[i] != s[i - 1]:
                            aj = 1
                    if i == 0:
                        aj = 1
            elif i > 3:
                if s[i] != s[i - 1]:
                    aj = 1

    ## Same as pt 1
    
    for i in range(0, len(s) - 1, 1):
        if int(s[i + 1]) < int(s[i]):
            dc += 1

    if aj > 0 and dc == 0:
        if x not in arr2:
            arr2.append(x)

print(len(arr2))

# lo: 929
# 1111 yeah
