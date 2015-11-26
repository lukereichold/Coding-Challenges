# Project Euler 17: Number letter counts

def numCharacters(numbers):
    return sum([len(num.replace(" ", "").replace("-", "")) for num in numbers])

nums_1_9 = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
nums_10_19 = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens_20_90 = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

nums_20_99 = []
for dec in tens_20_90:
    nums_20_99.append(dec)
    for digit in nums_1_9:
        nums_20_99.append(dec + "-" + digit)

first_hundred = list(nums_1_9)
first_hundred.extend(nums_10_19 + nums_20_99)

first_thousand = list(first_hundred)
for cent in nums_1_9:
    first_thousand.append(str(cent) + " hundred")
    for val in first_hundred:
        first_thousand.append(str(cent) + " hundred and " + str(val))

first_thousand.append("one thousand")
print numCharacters(first_thousand)
