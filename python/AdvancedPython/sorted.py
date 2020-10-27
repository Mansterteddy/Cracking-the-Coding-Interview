a = [(1, 2), (4, 1), (9, 10), (13, -3)]

b = sorted(a, key=lambda x: x[1])
print(b)

b = sorted(a, key=lambda x: -x[1])
print(b)