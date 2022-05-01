// bitset.c
// Řešení IJC-DU1, příklad a), 20.3.2021
// Autor: Veronika Molnárová, xmolna08, FIT-1BIT
// Přeloženo: gcc 9.3
// Deklaracia extern inline funkcii z bitset.h

#include "bitset.h"
#ifdef USE_INLINE
extern inline bitset_index_t bitset_size(bitset_t jmeno_pole);
extern inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, _Bool vyraz);
extern inline _Bool bitset_getbit(bitset_t jmeno_pole, bitset_index_t index);
#endif
