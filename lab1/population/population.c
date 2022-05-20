#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get initial population from user
    int s;
    do
    {
        s = get_int("Start Size: \n");
    }
    while (s < 8);

    // Get final population from user
    int e;
    do
    {
        e = get_int("End Size: \n");
    }
    while (e < s);

    //Calculate number of years
    int y = 0;
    while (s < e)
    {
        s = s + (s / 3) - (s / 4), y++;
    }

    //Print number of years
    printf("Years: %i\n", y);
}

