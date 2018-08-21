# args and kwargs

def test_args_kwargs(arg1, arg2, arg3):
    print("arg1: ", arg1)
    print("arg2: ", arg2)
    print("arg3: ", arg3)

args = ("two", 3, 5)
test_args_kwargs(*args)

kwagrs = {"arg3": 3, "arg2": "two", "arg1": 5}
test_args_kwargs(**kwagrs)