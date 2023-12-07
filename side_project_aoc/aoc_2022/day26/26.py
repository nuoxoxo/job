s = open('scrambled_mess').read().strip()
i = 0
S = len(s)
res, res2 = '', ''
while i < S - 1:
    if (s[i].isupper() or s[i] == '-') and s[i] == s[i + 1]:
        res += s[i]
        i += 2
        continue
    if s[i].isdigit() and s[i] == s[i + 1]:
        res2 += s[i]
        i += 2
        continue
    i += 1
print('p1:', res, '\np2:', res2)
