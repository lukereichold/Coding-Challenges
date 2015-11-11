# Project Euler #20: Factorial digit sum
from math import factorial as fact
sum = 0
for c in str(fact(100)):
    sum += int(c)
print(sum)
