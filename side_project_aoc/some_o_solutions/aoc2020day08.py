file = open('8.txt', 'r')
path = [x.split() for x in file.readlines()]


### Part 1

def bug(ls): # pass in a list
    
    trace = []
    for x in range(len(path)):
        w = 1;
        trace.append(w);
    
    n = 0
    accu = 0

    while n < len(ls):

        if trace[n] == 0:
            break

        if 'acc' in ls[n]:
            trace[n] = 0
            if '+' in ls[n][1]:
                accu += int(ls[n][1].rsplit('+')[1])
            elif '-' in ls[n][1]:
                accu -= int(ls[n][1].rsplit('-')[1])
            n += 1

        if 'nop' in ls[n]:
            trace[n] = 0
            n += 1

        if 'jmp' in ls[n]:
            trace[n] = 0
            if '+' in ls[n][1]:
                n += int(ls[n][1].rsplit('+')[1])
            elif '-' in ls[n][1]:
                n -= int(ls[n][1].rsplit('-')[1])

    return [accu, n]

print(bug(path))


## Part 2

def flip(n):
    if n == 'jmp':
        return 'nop'
    elif n == 'nop':
        return 'jmp'
    else:
        return n

def fix(ls):
    for x in range(len(ls)):
        if 'jmp' in ls[x] or 'nop' in ls[x]:
            pave = ls
            
            prev = ls[x][0]
            ls[x][0] = flip(ls[x][0])

            w = bug(ls)

            if w[1] >= len(path) - 1:
                print(w[0])
                break
            else:
                ls[x][0] = prev
                ls = pave

fix(path)
