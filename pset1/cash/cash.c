#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get change value
    float dollar;
    do
    {
        dollar = get_float("Change: ");
    }
    while (dollar < 0);

    //Convert decimal number to integer
    int cents = round(dollar * 100);

    //Amount of coins that are going to be
    int coins = 0;

    //Quarters delivered
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }
    //Dimes delivered
     while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
    //Nickels delivered
     while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
    //Pennies delivered
     while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }
    printf ("Coins: %i\n", coins);
}
