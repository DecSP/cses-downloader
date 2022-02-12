moves=[]
def f(n,namel,namer):
    if n==1:
        moves.append((namel,namer))
        return
    namemid=6-namel-namer
    f(n-1,namel,namemid)
    moves.append((namel,namer))
    f(n-1,namemid,namer)

n=int(input())
f(n,1,3)
print(len(moves))
for move in moves:
    print(move[0],move[1])
