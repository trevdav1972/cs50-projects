#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int j = 0;
    int k = 0;
    int i;
    do
    {
        i = get_int("Positive Number: ");
    }

    while (i < 1 || i > 8);
    int a = i;
    do
    {
        for (j = 0; j < i - 1; j++)
        {
            printf(" ");
        }


        for (k = j; k < a; k++)
        {
            printf("#");
        }

        printf("  ");

        for(k=j;k<a;k++)
        {
            printf("#");
        }
        printf("\n");
        i--;
    } while (i > 0);
}