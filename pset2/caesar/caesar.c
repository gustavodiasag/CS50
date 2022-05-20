#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool check_key(string s);
char encipher(string r, int k, int j);

int main(int argc, string argv[])
{
    if (argc == 2 && check_key(argv[1]))
    {
        int key = atoi(argv[1]);
        string p = get_string("plaintext: ");
        int p_size = strlen(p);
        encipher(p, key, p_size);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
bool check_key(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
char encipher(string r, int k, int j)
{
    printf("ciphertext: ");
    char c[j];
    for (int i = 0; i < j; i++)
    {
        if(isalpha(r[i]))
        {
            if (isupper(r[i]))
            {
                r[i] -= 'A';
                c[i] = (r[i] + k) % 26 + 'A';
                printf("%c", c[i]);
            }
            if (islower(r[i]))
            {
                r[i] -= 'a';
                c[i] = (r[i] + k) % 26 + 'a';
                printf("%c", c[i]);
            }
        }
        else
        {
            printf("%c", r[i]);
        }
    }
    printf("\n");
    return c[j];
}