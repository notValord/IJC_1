// steg-decode.c
// Řešení IJC-DU1, příklad b), 20.3.2021
// Autor: Veronika Molnárová, xmolna08, FIT-1BIT
// Přeloženo: gcc 9.3
// Hlada sifrovanu spravu z ppm suboru zakodovanu na LSb jednotlivych bytov s prvociselnym indexom

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "error.h"
#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"
#define START 23
#define CHANNELS 3

int main(int argc, char *argv[]){
    if (argc < 2){
        error_exit("Chyba argument");
    }

    struct ppm *picture = ppm_read(argv[1]);
    if(picture == NULL){
        error_exit("Chyba pri citani zo suboru\n");
    }

    int counter = 0;
    bitset_create(character, 8); //znak ako bitove pole

    bitset_alloc(primes, picture->ysize * picture->xsize * CHANNELS);
    Eratosthenes(primes);

    for (unsigned int i = START; i < picture->ysize * picture->xsize * 3; ++i) {
        if (bitset_getbit(primes,(i - 1))){ //bereme iba prvocisla
            continue;
        }
        if (counter > 7){  //nacitali sme cely znak
            printf("%c",(char) character[1]);
            if (character[1] == '\0'){  //koncime pri dosiahnuti '\0'
                printf("\n");
                break;
            }
            character[1] = 0;
            counter = 0;
        }
        bitset_setbit(character, counter,picture->data[i] & 1);
        counter++;
    }

    bitset_free(primes);
    ppm_free(picture);

    if (character[1] != '\0'){
        error_exit("Retazec nebol ukonceny znakom \'\\0\'");
    }

    return 0;
}