# Project Euler #6 - Sum square difference

sum_squares = sum([i**2 for i in range(1, 101)])
square_sum = sum([i for i in range(1, 101)]) ** 2
print(square_sum - sum_squares)