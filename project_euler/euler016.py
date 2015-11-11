# Project Euler #16: Power digit sum
power = 2 ** 1000
sum = 0
for c in str(power):
    sum += int(c)

print(power)
print(sum)
