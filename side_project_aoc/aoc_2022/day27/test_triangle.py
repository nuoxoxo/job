a,b,c=int(input()),int(input()),int(input())
print(-1 if(a+b<=c or b+c<=a or c+a<=b)else a+b+c)

x=[]
for i in [0,1,2]:
 x.append(int(input()))
print(-1 if 2*max(x)>=sum(x) else sum(x))

