#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//Declação de funções

int numletras(string texto);
int numpalavras(string texto);
int numsentencas(string texto);

int main(void){

    string texto;

    do{
        texto = get_string("Texto: ");
    }
    while (strlen(texto) == 0);

// Chamadas de funções

    int letras = numletras(texto);
    int palavras = numpalavras(texto);
    int sentencas = numsentencas(texto);

    //index = 0.0588 * L - 0.296 * S - 15.8
    float nivel = (((0.0588 * (((float)letras/(float)palavras)*100))) - (0.296 * (((float)sentencas/(float)palavras)*100)) - 15.8);

    //teste de funções
    //printf("%d\n", letras);
    //printf("%d\n", palavras);
    //printf("%d\n", sentencas);
    //printf("%f\n", nivel);

    if (nivel > 16){
        printf("Grade 16+\n");
    }
    else if (nivel < 1){
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade %.0f\n", nivel);
    }

}

int numletras(string texto){

    int contletras = 0, tamanho = strlen(texto);

    for (int i = 0; i <= tamanho; i++){

        if (isalpha(texto[i]) != 0){
            contletras++;
        }
    }

    return contletras;
}

int numpalavras(string texto){

    int contpalavras = 0, tamanho = strlen(texto);

    for (int i = 0; i <= tamanho; i++){

        if (texto[i] == ' '){
            contpalavras++;
        }

    }

    contpalavras++;
    return contpalavras;
}

int numsentencas(string texto){

    int contsetencas = 0, tamanho = strlen(texto);

    for (int i = 0; i <= tamanho; i++){

        if (texto[i] == 33 || texto[i] == 46 || texto[i] == 63){
            contsetencas++;
        }
    }

    return contsetencas;
}
