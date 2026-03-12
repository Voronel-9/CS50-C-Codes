#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int letrapontos[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int pontuação(string palavra);

int main(){

    string palavra1 = get_string("Player 1, digite sua palavra:\n");
    string palavra2 = get_string("Player 2, digite sua palavra:\n");

    int pontos1 = pontuação(palavra1);
    int pontos2 = pontuação(palavra2);

    if (pontos1 > pontos2){
        printf("Player 1 wins!\n");
    }
    else if (pontos1 < pontos2){
        printf("Player 2 wins!\n");
    }
    else{
        printf("Tie!\n");
    }

}

int pontuação(string palavra){

    int pontos = 0;

    for ( int i = 0, len = strlen(palavra); i < len; i++){

        if (isupper(palavra[i])){
            pontos += (letrapontos[palavra[i] - 65]);
        }
        else if(islower(palavra[i])){
            pontos += (letrapontos[palavra[i] - 97]);
        }
    }

    return pontos;
}

