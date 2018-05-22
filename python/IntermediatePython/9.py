def a_new_decorator(a_func):

    def wrapTheFunction():
        print("Boring before executing.")

        a_func()

        print("Boring after executing.")

    return wrapTheFunction

def a_function_requiring_decoration():
    print("Boring")

a_function_requiring_decoration()

a_function_requiring_decoration = a_new_decorator(a_function_requiring_decoration)

a_function_requiring_decoration()