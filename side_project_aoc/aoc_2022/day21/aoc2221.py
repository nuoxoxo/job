def main():
    fd = 0#1#0
    path = '2221.'
    data = open(path + str(fd)).read()
    print(parser(data))
    print(parser2(data))

def calc(R, M):
    if not type(R) is int:
        l, do, r = R
        if do == '+':
            return calc(M[l], M) + calc(M[r], M)
        if do == '-':
            return calc(M[l], M) - calc(M[r], M)
        if do == '/':
            return calc(M[l], M) // calc(M[r], M)
        if do == '*':
            return calc(M[l], M) * calc(M[r], M)
    return R

def parser(data):
    M = {}
    lines = data.splitlines()
    for line in lines:
        m, sym = line.split(':')
        sym = sym.split()
        if type(sym) is list and len(sym) == 1:
            sym = int(sym[0])
        M[m] = sym
    res = calc(M['root'], M)
    return res

# part 2

def calc2(name, M, mid):
    if name == 'humn':
    # if name == 'humn' and mid > -1:
        return mid
    if not type(M[name]) is int:
        #if name] == 'humn':
        #    return mid # binary search
        # l, do, r = R
        l, do, r = M[name]
        L = calc2(l, M, mid)
        R = calc2(r, M, mid)
        if do == '+':
            return L + R
            # return calc2(l, M, -1) + calc2(r, M, -1)
        if do == '-':
            return L - R
            # return calc2(l, M, -1) - calc2(r, M, -1)
            # return calc2(M[l], M, mid) - calc2(M[r], M, mid)
        if do == '/':
            return L / R
            # return calc2(l, M, -1) // calc2(r, M, -1)
            # return calc2(M[l], M, mid) // calc2(M[r], M, mid)
        if do == '*':
            return L * R
            # return calc2(l, M, -1) * calc2(r, M, -1)
            # return calc2(M[l], M, mid) * calc2(M[r], M, mid)
    return int(M[name])

def parser2(data):
    M = {}
    lines = data.splitlines()
    for line in lines:
        m, sym = line.split(':')
        sym = sym.split()
        if type(sym) is list and len(sym) == 1:
            sym = int(sym[0])
        M[m] = sym
    print('humn:', M['humn'])
    print('root:', M['root'])
    
    # JP's soln
    # which relies on the fact that expr is a linear polynomial function
    # x has only 1 value

    lhs = M['root'][0]
    rhs = M['root'][2]
    target = calc2(rhs, M, 0)
    
    l = 0
    h = int(1e20)
    while l < h:
        mid = (l + h) // 2
        dif = target - calc2(lhs, M, mid)
        if dif == 0:
            # print(mid)
            break
        elif dif > 0:
            h = mid
        elif dif < 0:
            l = mid
    return mid

# slow old way kept intact, to retry on campus

"""def calc2(R, M):
    if not type(R) is int and not type(R) is str:
        l, do, r = R
        ll = calc2(M[l], M)
        rr = calc2(M[r], M)
        # print(ll, do, rr)
        if type(ll) is not int or type(rr) is not int:
            return f'{ll}{do}{rr}'
        if do == '+':
            return calc2(M[l], M) + calc2(M[r], M)
        if do == '-':
            return calc2(M[l], M) - calc2(M[r], M)
        if do == '/':
            return calc2(M[l], M) // calc2(M[r], M)
        if do == '*':
            return calc2(M[l], M) * calc2(M[r], M)
        if do == '==':
            return calc2(M[l], M) == calc2(M[r], M)
    return R"""

if __name__ == '__main__':
    main()
