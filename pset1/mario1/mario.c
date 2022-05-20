cd #include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get integer integer from user
    int h;
    do
    {
        h = get_int("Height :\n");
    }
    while (h < 1 || h > 8);


    // Number of rows
    for (int i = 0; i < h; i++)
    {

        // First pyramid
        // Calculate number of spaces and hashes
        for (int j = 0; j < h; j++)
        {
            if (i + j < h - 1)
                printf (" ");

            else
                printf ("#");
        }

        // Separate the pyramids
        printf ("  ");

        // Second pyramid
        // Calculate number of hashes
        for (int j = 0; j <= i; j++)
            {
                printf ("#");
            }

        printf ("\n");
    }

}
