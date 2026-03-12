#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool keyvalida(string k);
int comvalido(string dcp);

int main (int argc, string argv[]){

    if (argc != 3 || comvalido(argv[argc-2]) == 2 || !keyvalida(argv[argc-1])){
        printf ("Usage: ./caesar cipher/decipher key\n");
        return 1;
    }

    //codificador -----------------------------------------------------------------------------

    if(comvalido(argv[argc-2]) == 0){

    string plaintext = get_string("plaintext: ");

    string ciphertext = plaintext;
    string converttext = plaintext;

    int key = atoi(argv[argc-1]);

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

    }else{

    string ciphertext = get_string("ciphertext: ");

    string plaintext = ciphertext;
    string converttext = ciphertext;

    int key = atoi(argv[argc-1]);

    for(int i = 0; i < strlen(ciphertext); i++){
        int dkey = 26 - (key % 26);
        if (isalpha(ciphertext[i])){
            if(isupper(ciphertext[i])){
                converttext[i] = ciphertext[i] - 65;
                converttext[i] = (converttext[i] + dkey) % 26;
                plaintext[i] = converttext[i] + 65;
            }else if(islower(ciphertext[i])){
                converttext[i] = ciphertext[i] - 97;
                converttext[i] = (converttext[i] + dkey) % 26;
                plaintext[i] = converttext[i] + 97;
            }
        }else{
            plaintext[i] = ciphertext[i];
        }
    }

    printf("plaintext: %s\n", plaintext);

    return 0;

    }
}

bool keyvalida(string k){
    for (int i = 0; i < strlen(k); i++){
        if (!isdigit(k[i])){
            return false;
        }
    }
    return true;
}

int comvalido(string dcp){
    string c = "cipher";
    string d = "decipher";

    if (strcmp(dcp, c) == 0){
        return (0);
    }else
    if(strcmp(dcp, d) == 0){
        return (1);
    }else{
        return (2);
    }
}
