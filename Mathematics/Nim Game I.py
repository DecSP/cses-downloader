t=int(input())
def solve():
	n=int(input())
	s=0
	for k in map(int,input().split()):
		s^=k
	print("first" if s!=0 else "second")
for i in range(t):
	solve()