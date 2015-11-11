# Euler 22: Names scores
with open('p022_names.txt') as f:
    names = sorted(f.read().split(","), key=str.lower)

    total_score = 0
    for i, name in enumerate(names):
        name = name.replace('\"','')
        alphabetical_score = sum([ord(c) - 64 for c in name])
        total_score += ((i+1) * alphabetical_score)
    print(total_score)
