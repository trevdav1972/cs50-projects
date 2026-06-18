#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);

int main(void)
{
    string text;
    float index = 0;
    float avel = 0;
    float aves = 0;
    int Words = 0;
    text = get_string("Text: ");
    Words = strlen(text);

    avel = count_letters(text) / (float) count_words(text); avel *= 100;
    aves = count_sentences(text) / (float) count_words(text); aves *= 100;
    index = 0.0588 * avel - 0.296 * aves - 15.8;


    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round (index));

    }


}

int count_letters(string text)
{
    int Length = strlen(text);
    int b = 0;
    for (int i = 0; i < Length; i++)
    {
            if (isalpha(text[i]))
        {
            b = b + 1;
        }
    }
    return b;
}

int count_words(string text)
{
    int Length = strlen(text);
    int a = 1;
    for (int i = 0; i < Length; i++)
        {
            if (isspace(text[i]))
         {
            a = a + 1;
         }
        }
        return a;
}

int count_sentences(string text)
{
    int Length = strlen(text);
    int c = 0;
    for (int i = 0; i < Length; i++)
    {
            if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            c = c + 1;
        }
    }
    return c;
}
