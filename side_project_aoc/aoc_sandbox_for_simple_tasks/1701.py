s = open('_inputs_/1701.0').read().strip()
res = 0
for i in range(len(s)):
    R = i + 1
    if R == len(s):
        R = 0
    if s[i] != s[R]:
        continue
    res += int(s[i])
res2 = 0
mid = len(s) // 2
for i in range(mid):
    if s[i] == s[i + mid]:
        res2 += 2 * int(s[i])
print(res)
print(res2)
