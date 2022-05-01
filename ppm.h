// ppm.h
// Řešení IJC-DU1, příklad b), 20.3.2021
// Autor: Veronika Molnárová, xmolna08, FIT-1BIT
// Přeloženo: gcc 9.3
// Deklaracie struktury ppm a funkcii na citanie suboru a uvolnenie alokovanej struktury

#ifndef IJC_PPM_H
#define IJC_PPM_H

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);
void ppm_free(struct ppm *p);

#endif //IJC_PPM_H
