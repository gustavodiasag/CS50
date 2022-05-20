#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Prompt the user for credit card number
    const long num;
    do
    {
        num = get_long("Credit Card Number: ");
    }
    while (num < 0);

    int digits, checksum = 0;
    
    //Calculate the number of digits in the number
    for (digits = 0; num > 0; digits++, num /= 10)
    {
        //While calculating, determine the digits in the
        //Even positions and add them to the checksum
        if (digits % 2 == 0)
        {
            checksum += num % 10;
        }
        //Do the same for the odd digits multiplying them by 2
        else
        {
            int odd = (num % 10) * 2;
            //Separate the digits in the number and add them separately
            if (odd > 9)
            {
                checksum += ((odd / 10) + (odd % 10));
            }
            else
            {
                checksum += odd;
            }
        }

    }
    checksum %= 10;
 
    //Conditions for each card
    if ((checksum == 0) && ((number >= 4e12 && number < 5e12) || (number >= 4e15 && number < 5e15)))
    {
        printf("VISA\n");
    }
    else if ((checksum == 0) && (number >= 51e14 && number < 56e14))
    {
        printf("MASTERCARD\n");
    }
    else if ((checksum == 0) && ((number >= 34e13 && number < 35e13) || (number >= 37e13 && number < 38e13)))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}