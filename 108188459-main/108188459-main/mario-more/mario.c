#include <stdio.h>
#include <cs50.h>

int main()
{
    int linha, coluna, espaco;
    int altura = 0;

    do{
        altura = get_int("Altura: ");
    }
    while (altura < 1 || altura > 8);

    for (linha = 0; linha < altura; linha++)
    {
        for (espaco = 0; espaco < altura - linha - 1; espaco++)
        {
            printf(" ");
        }
        for (coluna = 0; coluna <= linha; coluna++)
        {
            printf("#");
        }

        printf("  ");

        for (coluna = 0; coluna <= linha; coluna++)
        {
            printf("#");
        }

        printf("\n");
        
    }
}
