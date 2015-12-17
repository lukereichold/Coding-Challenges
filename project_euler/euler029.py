# Project Euler Problem #29 - Distinct powers

from math import pow

products = []
for a in range(2, 101):
    for b in range(2, 101):
        products.append(pow(a,b))

print(len(set(products)))

