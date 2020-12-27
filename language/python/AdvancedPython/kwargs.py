def greet_me(**kwagrs):
    for key, value in kwagrs.items():
        print("{0} == {1}".format(key, value))

greet_me(name="yasoob", id="1234")