// primes.c
// Řešení IJC-DU1, příklad a), 20.3.2021
// Autor: Veronika Molnárová, xmolna08, FIT-1BIT
// Přeloženo: gcc 9.3
// Najdenie a vypisanie poslednych 10-tich prvocisel z 200 milionov

#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "bitset.h"
#include "eratosthenes.h"
#include "error.h"
#define ARRAY_SIZE 200000000
#define PRIMES 10


int main() {
    clock_t start = clock();
    int counter = 1;

    bitset_create(primes, PRIMES * B_ULONG);
    bitset_create(array, ARRAY_SIZE); //TODO

    Eratosthenes(array);

    for (bitset_index_t i = (array[0] - 1) * B_ULONG; i > 0; --i) {  //najdeme poslednych 10 prvocisel
        if (bitset_getbit(array, (i-1)) == 0){  //indexovanie je o 1 mensie
            primes[counter] = i;
            counter++;
        }
        if (counter == PRIMES + 1){
            break;
        }
    }

    for (int i = PRIMES; i > 0; --i) {
        printf("%lu\n", primes[i]);
    }

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}