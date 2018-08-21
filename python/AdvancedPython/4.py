def generator_function():
    for i in range(3):
        yield i

gen = generator_function()
print(next(gen))
print(next(gen))
print(next(gen))
#print(next(gen))

my_string = "Microsoft"
#next(my_string)
my_iter = iter(my_string)
print(next(my_iter))