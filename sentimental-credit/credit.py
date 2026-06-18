# TODO
from cs50 import get_int
import sys

number = get_int("Number:" )

even = 0
two_digit = 0 # This will store the last two digits
i = 0 # This is to count the amount of digits in the credit card number, and while the function is going on we can see if the number is odd or even.
oddsum = 0 # This number by the end of the while function will end up adding all the oddnumbers from right to left
evensum = 0 # This number by the end of the while function will end up adding all the evennumbers from right to left

while number > 0:
    if i % 2 == 0:
        j = number % 10
        oddsum += j
        i = i + 1
    else:
        j = number % 10
        j *= 2
        if j >= 10:
            a = j % 10
            b = j // 10
            evensum += a + b
            i = i + 1
        else:
            evensum += j
            i = i + 1
    number //= 10
    if number > 9 and number < 100:
        two_digit = number

evensum = evensum + oddsum

if evensum % 10 != 0:
    print("INVALID")
    sys.exit(0)
if i in [16, 13]:
    if two_digit in [40, 41, 42, 43, 44, 45, 46, 47, 48, 49]:
        print("VISA")
        sys.exit(1)
if i == 16:
    if two_digit in [51, 52, 53, 54, 55]:
        print("MASTERCARD")
        sys.exit(1)
if i == 15:
    if two_digit in [34, 37]:
        print("AMEX")
        sys.exit(1)
    else:
        print("INVALID")
        sys.exit(0)
else:
    print("INVALID")
    sys.exit(0)

