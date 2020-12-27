# Raw map implementation
items = [1, 2, 3, 4, 5]
squared = []
for i in items:
    squared.append(i**2)
print(squared)

# Map
squared = list(map(lambda x: x**2, items))
print(squared)

def multi(x):
    return x**2

squared = list(map(multi, items))
print(squared)

def multiply(x):
    return (x*x)

def add(x):
    return (x+x)

funcs = [multiply, add]
for i in range(5):
    value = list(map(lambda x: x(i), funcs))
    print(value)


