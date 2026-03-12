#include <stdio.h>
#include <cs50.h>

int main()
{

    int valortotal, valorpag;

    do
    {
        valortotal = get_int("Total: ");
    }
    while (valortotal < 0);

    do
    {
        valorpag = get_int("Quantia paga: ");
    }
    while (valorpag < 0);

    valorpag = valorpag - valortotal;

    if (valorpag < 0)
    {
        printf ("Pagamento insuficiente.\n");
    }
    else
    {
        int quarters = valorpag / 25;
        int dimes = (valorpag % 25) / 10;
        int nickles = ((valorpag % 25) % 10) / 5;
        int pennies = (((valorpag % 25) % 10) % 5) / 1;

        int totalmoedas = quarters + dimes + nickles + pennies;

        printf ("Diferença: %d\n", valorpag);
        printf ("Troco: %d quarters, %d dimes, %d nickles, %d pennies. %d moedas.\n",
                 quarters, dimes, nickles, pennies, totalmoedas);
    }
}
