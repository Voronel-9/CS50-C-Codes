#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: ./recover file\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    if(card == NULL){
        printf("Card %s not found.\n", argv[1]);
        return 1;
    }

    FILE *cardread = NULL;
    BYTE buffer[512];
    int filecount = 0;
    char name[8] = {0};

    while (fread(buffer, sizeof(uint8_t)*512, 1, card) == 1){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3]&0xf0) == 0xe0){
            if(cardread != NULL){
                fclose(cardread);
            }

            sprintf(filename, "%03d.jpg", filecount++);

            cardread = fopen(filename, "w");
        }

        if(cardread != NULL){
            fwrite(buffer, sizeof(uint8_t)*512, 1, cardread);

        }
    }

    if (cardread != NULL){
    fclose(cardread);
    }
    fclose(card);
}
