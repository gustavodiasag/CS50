#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool check_key(string s);
int main(int argc, string argv[])
{
    if (argc != 2 || !check_key(argv[1]))
    {
        printf("Key must contain 26 unrepeated characters.\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        char ciphertext[strlen(plaintext)];
        int i = 0;
        for (i = 0; i < strlen(plaintext); i++)
        {
            string key = argv[1];
            char p = plaintext[i];
            if (isalpha(p))
            {
                if (isupper(p))
                {
                    ciphertext[i] = toupper(key[p - 'A']);
                }
                if (islower(p))
                {
                    ciphertext[i] = tolower(key[p - 'a']);
                }
            }
            else
            {
                ciphertext[i] = p;
            }
        }
        ciphertext[i] = '\0';
        printf("ciphertext: %s\n", ciphertext);
    }
}
bool check_key(string s)
{
    int i = 0;
    for (i = 0; i < strlen(s); i++)
    {
        for (int j = 0; j < strlen(s); j++)
        {
            if (s[j] == s[!j] || s[j] == s[j + 1])
            {
                return false;
            }
        }
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    if (i != 26)
    {
        return false;
    }
    return true;
}