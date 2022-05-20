from cs50 import get_int

def main():

    while True:
        num = get_int("Credit Card Number: ")
        if num > 0:
            break

    digits = 0
    checksum = 0

    for digits in range(num, 0, 1):
        if (digits % 2) == 0:
            checksum += (num % 10)
        else:
            odd = ((num % 10) * 2)
            if odd > 9:
                checksum += ((odd / 10) + (odd % 10))
            else:
                checksum += odd
        num /= 10

    checksum %= 10

    if checksum == 0 and ((num >= 4e12 and num < 5e12) or (num >= 4e15 and num < 5e15)):
        print("VISA")
    elif checksum == 0 and (num >= 51e14 and num < 56e14):
        print("MASTERCARD")
    elif (checksum == 0) and ((num >= 34e13 and num < 35e13) or (num >= 37e13 and num < 38e13)):
        print("AMEX")
    else:
        print("INVALID")

main()