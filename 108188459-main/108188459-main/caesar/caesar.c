#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool keyvalida(string k);

int main (int argc, string argv[]){

    if (argc != 2 || !keyvalida(argv[argc-1])){
        printf ("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    string ciphertext = plaintext;
    string converttext = plaintext;

    int key = atoi(argv[1]);

    for(int i = 0; i < strlen(plaintext); i++){
        if (isalpha(plaintext[i])){
            if(isupper(plaintext[i])){
                converttext[i] = plaintext[i] - 65;
                converttext[i] = (converttext[i] + key) % 26;
                ciphertext[i] = converttext[i] + 65;
            }else if(islower(plaintext[i])){
                converttext[i] = plaintext[i] - 97;
                converttext[i] = (converttext[i] + key) % 26;
                ciphertext[i] = converttext[i] + 97;
            }
        }else{
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool keyvalida (string k){
    for (int i = 0; i < strlen(k); i++){
        if (!isdigit(k[i])){
            return false;
        }
    }
    return true;
}
