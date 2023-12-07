a = ['python', 'qwe', 'pop']
print(a)
print( _ for _, x in enumerate(reversed(a)))
a.reverse()
print(a)

for n in reversed(range(12, 12+4)):
    print(n)
