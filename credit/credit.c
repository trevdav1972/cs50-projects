#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long i;
    long two = 0;
    long four = 0;
    long six = 0;
    long eight = 0;
    long ten = 0;
    long twelve = 0;
    long fourteen = 0;
    long sixteen = 0;
    int check = 0;

    do
    {
        i = get_long("Number: ");
    }
    while (i < 1);

    long x = i;
    long copy = i;
    long copy1 = i;
    long copy2 = i;
    long copy3 = i;
    long copy4 = i;
    long copy5 = i;
    two = (i / 10);
    two = (two % 10);
    four = (i / 1000);
    four = (four % 10);
    six = (i / 100000);
    six = (six % 10);
    eight = (i / 10000000);
    eight = (eight % 10);
    ten = (i / 1000000000);
    ten = (ten % 10);
    twelve = (i / 100000000000);
    twelve = (twelve % 10);
    fourteen = (i / 10000000000000);
    fourteen = (fourteen % 10);
    sixteen = (i / 1000000000000000);
    sixteen = (sixteen % 10);

    two *= 2;
    four *= 2;
    six *= 2;
    eight *= 2;
    ten *= 2;
    twelve *= 2;
    fourteen *= 2;
    sixteen *= 2;


    int evensum = 0;
    if (two >= 10)
    {
    int a =  two % 10;
    int b = two / 10;
    evensum = evensum + a + b;
    }
    else
    evensum = evensum + two;

    if (four >= 10)
    {
    int a =  four % 10;
    int b = four / 10;
     evensum = evensum + a + b;
    }
    else
    evensum = evensum + four;

    if (six >= 10)
    {
        int a =  six % 10;
        int b = six / 10;
        evensum = evensum + a + b;
    }
    else
    evensum = evensum + six;

    if (eight >= 10)
    {
    int a =  eight % 10;
    int b = eight / 10;
     evensum = evensum + a + b;
    }
    else
    evensum = evensum + eight;

    if (ten >= 10)
    {
    int a =  ten % 10;
    int b = ten / 10;
     evensum = evensum + a + b;
    }
    else
    evensum = evensum + ten;

    if (twelve >= 10)
    {
    int a =  twelve % 10;
    int b = twelve / 10;
     evensum = evensum + a + b;
    }
    else
    evensum = evensum + twelve;

    if (fourteen >= 10)
    {
    int a =  fourteen % 10;
    int b = fourteen / 10;
     evensum = evensum + a + b;
    }
    else
    evensum = evensum + fourteen;

    if (sixteen >= 10)
    {
    int a =  sixteen % 10;
    int b = sixteen / 10;
     evensum = evensum + a + b;
    }
    else
    evensum = evensum + sixteen;


    int oddsum = 0;
    int digits = 1;


    do
    {
        int ld = x % 10;
        if (digits % 2 == 1)
        {
           oddsum += ld;
        }
        x = x / 10;
        digits++;

    } while (x > 0);
    int sum = oddsum + evensum;

    sum = sum % 10;

    int d = 0;
    if (sum == 0)
    {
        d = 1;
    }


    int increment = 0;
    do
    {
        copy5 = copy5 / 10;
        increment++;
    }
    while (copy5 > 0);

    if (d == 0 && check == 0)
    {
        printf("INVALID\n");
        check = 1;
    }
    if (increment == 15 && check == 0)
    {
        copy1 = copy / 10000000000000;
        if (copy1 == 34 || copy1 == 37)
        {
            printf ("AMEX\n");
            check = 1;
        }
    }
    if (increment == 16 && check == 0)
    {
        copy2 = copy / 100000000000000;
        if (copy2 == 51 || copy2 == 52 || copy2 == 53 || copy2 == 54 || copy2 == 55)
        {
            printf ("MASTERCARD\n");
            check = 1;
        }
    }
    if (increment == 13 && check == 0)
    {
    copy3 = copy / 1000000000000;
    if (copy3 == 4)
    {
        printf ("VISA\n");
        check = 1;
    }
    }
    if (increment == 16 && check == 0)
    {
        copy4 = copy / 1000000000000000;
        if (copy4 == 4)
        {
            printf ("VISA\n");
            check = 1;
        }
    }
    if (check == 0)
    {
        printf("INVALID\n");
    }

}