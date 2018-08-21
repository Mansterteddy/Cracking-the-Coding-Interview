items = [1, 2, 3, 4, 5]
squared = []
for i in items:
    squared.append(i**2)

squared = list(map(lambda x: x**2, items))
print(squared)

def multiply(x):
    return (x*x)

def add(x):
    return (x+x)

funcs = [multiply, add]
for i in range(5):
    value = list(map(lambda x: x(i), funcs))
    print(value)

add = lambda x, y: x + y
print(add(3, 5))

a = [(1, 2), (4, 1), (9, 10), (13, -3)]
a.sort(key=lambda x: x[1])

