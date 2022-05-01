// eratosthenes.h
// Řešení IJC-DU1, příklad a), 20.3.2021
// Autor: Veronika Molnárová, xmolna08, FIT-1BIT
// Přeloženo: gcc 9.3
// Deklaracie funkcie eratosthenes

#ifndef IJC_ERATOSTHENES_H
#define IJC_ERATOSTHENES_H

#include "bitset.h"

void Erato_prepare(bitset_t pole, bitset_index_t size);
void Eratosthenes(bitset_t pole);

#endif //IJC_ERATOSTHENES_H
