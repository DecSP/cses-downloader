from math import sqrt
n=int(input())
# (d: 1 to sqrt(n)) d *(n/d-sqrt(n)) + (m: 1 to sqrt(n)) sum of (1..n/m)

MOD=1000000007
def sumFrom1(n):
	global MOD
	return (int((n*(n+1))//2))%MOD

sqn=int(sqrt(n))
first=0
for d in range(1,sqn+1):
	first=(first+d*(n//d-sqn))

second=0
for m in range(1,sqn+1):
	second=(second+sumFrom1(n//m))%MOD

print((first+second)%MOD)