n = int(input())
s = 1
for i in range(0,n+1):
    if i == 0 or i == 1:
        s = 1
    else:
        s *= i
a = str(s)
c = []
for i in a:
    c.append(i)
d = list(map(int,c))
print(d)