// ppm.c
// Řešení IJC-DU1, příklad b), 20.3.2021
// Autor: Veronika Molnárová, xmolna08, FIT-1BIT
// Přeloženo: gcc 9.3
// Definicie funkcii na citanie ppm suboru a uvolnenie alokovanej ppm struktury

#include "ppm.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HELPER_MAX 10
#define CHANNELS 3
#define MAX_LIMIT 8000

struct ppm * ppm_read(const char * filename){
    char helper[HELPER_MAX] = "";
    int x = 0, y = 0;
    FILE *fp;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        warning_msg("Chyba pri otvarani suboru\n");
        return NULL;
    }

    if( fgets(helper,HELPER_MAX,fp), strcmp(helper, "P6\n") != 0){  //kontrola formatu ppm
        warning_msg("Zadany subor nie je formatu ppm\n");
        fclose(fp);
        return NULL;
    }

    fscanf(fp,"%d %d", &x, &y);

    if (x * y > MAX_LIMIT* MAX_LIMIT){
        x = MAX_LIMIT;
        y = MAX_LIMIT;
    }

    fgets(helper,HELPER_MAX,fp); //Docita sa riadok na ktorom su cisla

    if(fgets(helper,HELPER_MAX,fp), strcmp(helper, "255\n") != 0){  //format ppm
        warning_msg("Zadany subor nie je spravneho formatu ppm\n");
        fclose(fp);
        return NULL;
    }

    struct ppm *picture = malloc(sizeof(struct ppm) + (x * y * CHANNELS));
    if (picture == NULL){
        warning_msg("Chyba pri alokacii\n");
        fclose(fp);
        return NULL;
    }

    picture->xsize = x;
    picture->ysize = y;
    strcpy(picture->data, "");

    if(fread(picture->data, 1, (x * y * CHANNELS),fp) < (unsigned long) (x * y * CHANNELS)){
        warning_msg("Chyba pri citani dat z ppm suboru\n");
        fclose(fp);
        ppm_free(picture);
        return NULL;
    }

    fclose(fp);
    return picture;
}

void ppm_free(struct ppm *p){
    free(p);
}