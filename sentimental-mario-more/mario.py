# TODO
def main():
    from cs50 import get_int
    i = 0
    j = 8
    a = 0
    b = 1
    d = 0
    Check(a)
    while True:
        for i in range(a-1-d):
            print(f" ", end="")
            i += 1
        print("#" * b, end="")
        print ("  ", end="")
        print ("#" * b)
        b += 1
        d += 1
        if b > a:
            break
Check (a)
    while True:
    a = get_int("Positive Number: ")
    if a > 0 and a <= 8:
        break