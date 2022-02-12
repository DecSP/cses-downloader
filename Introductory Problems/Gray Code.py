n=int(input())
for i in range(2**n):
	print(bin(i^(i>>1))[2:].zfill(n))