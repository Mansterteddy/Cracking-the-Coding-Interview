number_list = range(-5, 5)
less_than_zero = list(filter(lambda x: x < 0, number_list))
print(less_than_zero)

def less(x):
    return x < 0

less_than_zero = list(filter(less, number_list))
print(less_than_zero)