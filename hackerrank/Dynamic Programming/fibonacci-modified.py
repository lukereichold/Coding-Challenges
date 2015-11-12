# Fibobacci Modified: https://www.hackerrank.com/challenges/fibonacci-modified
A, B, N = [int(x) for x in input().split()]
fibs = [0, A, B]

for i in range(3, N+1):
    val = (fibs[i-1] ** 2) + fibs[i-2]
    fibs.append(val)

print(fibs[N])