# List Comprehension
multiples = [i for i in range(30) if i % 3 is 0]
print(multiples)

squared = [x**2 for x in range(10)]
print(squared)

# Dictionary Comprehension
mcase = {'a': 10, 'b': 34, 'A': 7, 'Z': 3}
mcase_frequency = {k.lower(): mcase.get(k.lower(), 0) + mcase.get(k.upper(), 0) for k in mcase.keys()}
print(mcase_frequency)

new_mcase = {v: k for k, v in mcase.items()}
print(new_mcase)

# Set Comprehension
squared = {x**2 for x in [1, 1, 2]}
print(squared)

squared = {x**2 for x in [1, 1, 2] if x != 2}
print(squared)