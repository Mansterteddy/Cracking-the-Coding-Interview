my_list = ['apple', 'banana', 'grapes', 'pear']

for c, value in enumerate(my_list):
    print(c, value)

for c, value in enumerate(my_list, 1):
    print(c, value)