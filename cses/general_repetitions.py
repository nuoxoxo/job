s = input()
t = -1 * 1e9
i = 0
while i < len(s) - 1:
    temp = 1;
    if s[i] == s[i + 1]:
        while i + 1 < len(s) and s[i] == s[i + 1]:
            temp += 1
            i += 1
        t = t if t > temp else temp
    else:
        i += 1
t = 1 if t < 0 else t
print(int(t))
