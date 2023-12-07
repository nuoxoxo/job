enco = []
with open('9.txt') as file:
    for line in file:
        enco.append(int(line.rstrip()))

### test
# print(prem)
# print(len(prem))


### Part 1

def check(a):
    
    c = 25
    
    while c < len(a):
        
        count = 0
        
        for x in range(c - 25, c - 1):
            for y in range(x + 1, c):
                if a[x] + a[y] == a[c]:
                    count = 1
        if count == 0:
            break
        elif count == 1:
            c += 1
    return a[c]
        
w = check(enco)
print(w)


### Part 2

def encryption_weakness(a):
    
    sub = []
    weakness = 0 
    
    for x in range(len(a)):
        
        c = a[x]
        
        for y in range(x + 1, len(a)):
            c += a[y]
            if c == w:
                for z in range(x, y + 1):
                    sub.append(a[z])
                # print(sub)
                
                weakness = min(sub) + max(sub)
                
                break
    
    return weakness

final = encryption_weakness(enco)
print(final)
