# Project Euler #30 - Digit fifth powers

from math import pow

nums = []
for i in range(10, 2**22): # try up to 4M
    five_sum = sum([int(d)**5 for d in str(i)])
    if i == five_sum:
        nums.append(five_sum)

print(sum(nums))
