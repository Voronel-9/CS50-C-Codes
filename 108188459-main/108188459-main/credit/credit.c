#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main()
{
    long crednum, numcount, cardcheck;
    int credmult = 0, credadd = 0, credlen = 0, doisdigitos = 0;

    crednum = get_long ("Insert Valid Credit Card Number: ");

    numcount = crednum;
    cardcheck = crednum;

    do
    {
        numcount /= 10;
        ++credlen;
    }
    while (numcount != 0);

    if (credlen == 13 || credlen == 15 || credlen == 16)
    {
        do
        {
        credadd += crednum % 10;
        crednum /= 10;
        credmult = (crednum % 10) * 2;
            do
            {
                credadd += credmult % 10;
                credmult /= 10;
            }
            while (credmult != 0);
        crednum /= 10;
        } while (crednum != 0);

        doisdigitos = cardcheck / pow(10, credlen - 2);

        if((credadd % 10) == 0)
        {
            if ((doisdigitos == 34 || doisdigitos == 37) && credlen == 15)
            {
                printf("AMEX\n");
            }
            else
            {
                if ((doisdigitos >= 51 && doisdigitos <= 55) && credlen == 16)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    if ((doisdigitos >=40 && doisdigitos <= 49) && (credlen == 13 || credlen == 16))
                    {
                        printf("VISA\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
