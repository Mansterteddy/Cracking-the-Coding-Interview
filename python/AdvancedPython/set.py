some_list = ['a', 'b', 'c', 'd', 'b', 'm', 'n', 'n']
duplicates = set([x for x in some_list if some_list.count(x) > 1])
print(duplicates)

a_set = {'red', 'blue', 'green'}
print(type(a_set))