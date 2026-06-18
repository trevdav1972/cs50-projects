#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Start Size: ");
    }
    while (n < 9);
    // TODO: Prompt for start size
    int end;
    do
    {
        end = get_int("End Size: ");
    }
    while (end < n);
    // TODO: Prompt for end size
    int copy = end;
    int llamas = n;
    int a = 0;
    while (llamas < copy)
    {
        n = n + (n / 3) - (n / 4);
        llamas = n;
        a++;
    }
    // TODO: Calculate number of years until we reach threshold
    printf("Years: %i\n", a);
    // TODO: Print number of years
    return 0;
}
