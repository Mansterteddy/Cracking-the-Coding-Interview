# lambda function
add = lambda x, y: x + y
print(add(3, 5))

a = [(1, 2), (4, 1), (9, 10), (13, -3)]
b = sorted(a, key=lambda x: -x[1])
print(b)

add_triple = lambda x, y, z: x + y + z
print(add_triple(3, 4, 5))