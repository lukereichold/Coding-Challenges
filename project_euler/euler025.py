# Euler Problem 25: Find first 1000-digit Fibonacci number
fibs = [1, 1]
i = 2;
while True:
    next = fibs[i-2] + fibs[i-1]
    if len(str(next)) >= 1000:
        print(i+1)
        break
    else:
        fibs.append(next)
    i += 1
