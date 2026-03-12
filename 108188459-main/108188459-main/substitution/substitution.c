#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool keyvalida(string k);

int main(int argc, string argv[])
{

    if (argc != 2 || !keyvalida(argv[argc - 1]))
    {
        printf("Usage: ./subtitution key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    string ciphertext = plaintext;
    
    string keyc = argv[argc - 1];
    char keyd[26], keyu[26], keyl[26];

    for (int i = 0; i < 26; i++)
    {
        keyu[i] = toupper(keyc[i]);
    }
    for (int i = 0; i < 26; i++)
    {
        keyl[i] = tolower(keyc[i]);
    }

    int plainlen = strlen(plaintext);

    for (int i = 0; i < plainlen; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int index = plaintext[i] - 65;
                ciphertext[i] = keyu[index];
            }
            else if (islower(plaintext[i]))
            {
                int index = plaintext[i] - 97;
                ciphertext[i] = keyl[index];
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool keyvalida(string k)
{
    int len = strlen(k);
    char alphabetholder[26] = {""};
    int i = 0;

    if (len != 26)
    {
        printf("Tamanho errado.");
        return false;
    }

    for (i = 0; i < len; i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Não há apenas letras.");
            return false;
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (isupper(k[i]))
        {
            int knum = k[i] - 65;
            alphabetholder[knum] = k[i];
            // printf ("upper\n");
        }
        if (islower(k[i]))
        {
            int knum = k[i] - 97;
            alphabetholder[knum] = k[i];
            // printf ("lower\n");
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (!isalpha(alphabetholder[i]))
        {
            printf("O alfabeto não está completo.\n");
            return false;
        }
    }

    return true;
}
