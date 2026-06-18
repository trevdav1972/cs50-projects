#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./substition key\n");
        return 1;
    }
    string key = argv[1];
    printf("%s\n", key);

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0; i < 26; i++)
    {
        argv[1][i] = tolower(argv[1][i]);
    }

    for (int i = 0; i < 25; i++)
    {

        for (int b = i + 1; b < 26; b++)
        {
            if (key[i] == key[b])
            {
                printf("Key must not contain repeated characters.");
                return 1;
            }
        }
        if (!isalpha(key[i]))
            {
                printf("Key must only contain alphabetic characters.");
                return 1;
            }

    }

    string plaintext = get_string("plaintext: ");

    for (int a = 0; a < strlen(plaintext); a++)
    {

        for (int i = 0; i < 26; i++)
        {
            if (isupper(plaintext[a]))
            {
                if (plaintext[a] == 65 + i)
                {
                    plaintext[a] =  toupper(key[i]);
                    break;
                }
            }

            else if (islower(plaintext[a]))
            {
                if (plaintext[a] == 97 + i)
                {
                    plaintext[a] = key[i];
                    break;
                }
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}




