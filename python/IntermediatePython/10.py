from functools import wraps

def a_new_decorator(a_func):
    @wraps(a_func)
    def wrapTheFunction():
        print("Boring before executing.")

        a_func()

        print("Boring after executing.")

    return wrapTheFunction

@a_new_decorator
def a_function_requiring_decoration():
    print("Boring")

a_function_requiring_decoration()
print(a_function_requiring_decoration.__name__)