#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{   
    //Prompt the user for any body of text
    string text = get_string("Text: ");
    
    float letters = 0, sentences = 0, words = 1;
    
    //Calculate the number of words, letters and sentences
    for (int i = 0, text_length = strlen(text); i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }
        if (isspace(text[i]))
        {
            words++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    //Calculate grade related to the readability
    //of the text based on the Coleman-Liau index
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    //Print the indication of each grade
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 16 && index >= 1)
    {
        int grade = index;
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Before Grade 1\n");
    }
}