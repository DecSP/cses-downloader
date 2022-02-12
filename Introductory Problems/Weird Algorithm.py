n=int(input())
l=[str(n)]
while n!=1:
    if n%2:
       n=n*3+1
       l.append(str(n))
    else:
        n//=2
        l.append(str(n))
print(" ".join(l))
