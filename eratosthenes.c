// eratosthenes.c
// Řešení IJC-DU1, příklad a), 20.3.2021
// Autor: Veronika Molnárová, xmolna08, FIT-1BIT
// Přeloženo: gcc 9.3
// Definicia funkcie eratosthenes na hladanie prvocisel

#include <stdio.h>
#include <time.h>
#include "error.h"
#include "eratosthenes.h"
#include "bitset.h"
#include <math.h>

// 0 == prvocislo
// 1 == zlozene cislo

// Predpripravuje bitove pole, jednotku a nasobky 2 nastavi na zlozene cisla
// Nepocita s 0 (nie je prvocislo ani prirodzene cislo)
void Erato_prepare(bitset_t pole, bitset_index_t size){
    bitset_setbit(pole, 0, 1);
    bitset_index_t even = 0xAAAAAAAA;
    for (bitset_index_t i = 1; i < size; ++i) {
        pole[i] = pole[i] | even;
    }
    bitset_setbit(pole, 1, 0); // 2 je prvocislo
}

void Eratosthenes(bitset_t pole){
    bitset_index_t size = pole[0];
    bitset_index_t max_n = sqrtl(((size - 1) * B_ULONG));

    Erato_prepare(pole, size);

    for (bitset_index_t i = 3; i < max_n; i += 2) {  //hlada prvocisla od 3, po sqrt(n)
        if (bitset_getbit(pole, (i-1)) == 0){
            for (bitset_index_t j = i * i; j <= (size - 1) * B_ULONG; j += i) { //nastavi vsetky nasobky na zlozene cisla
                if (bitset_getbit(pole, (j-1))){
                    continue;
                }
                bitset_setbit(pole, (j-1), 1);
            }
        }
    }
}


