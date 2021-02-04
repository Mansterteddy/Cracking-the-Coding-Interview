def square_root(a):
    return find_root(lambda x: square(x) - a)

def logarithm(a, base=2):
    return find_rrot(lambda x: pow(base, x) - a)