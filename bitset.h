// bitset.h
// Řešení IJC-DU1, příklad a), 20.3.2021
// Autor: Veronika Molnárová, xmolna08, FIT-1BIT
// Přeloženo: gcc 9.3
// Definicie inline funkcii a makier na pracu so strukturami bitset_t

#ifndef IJC_BITSET_H
#define IJC_BITSET_H
#define B_ULONG 32

typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;

#define bitset_create(jmeno_pole, velikost) \
    bitset_index_t jmeno_pole[(velikost-1)/B_ULONG+2] = {0}; \
    jmeno_pole[0] = (velikost - 1)/B_ULONG + 2;              \
    static_assert(velikost > 0, "Invalid size of an array")                                            \
// Velkost pole obsahuje aj prvy prvok s jeho velkostou
// Vytvori a nuluje lokalne pole

#define bitset_alloc(jmeno_pole, velikost) \
   assert(velikost > 0 && "Invalid size of an array"); \
   bitset_t jmeno_pole = calloc((velikost - 1)/B_ULONG + 2, sizeof(bitset_index_t)); \
   assert(jmeno_pole != NULL && "bitset_alloc: Chyba alokace pamate \n");         \
   jmeno_pole[0] = (velikost - 1)/B_ULONG + 2
// Velkost pole obsahuje aj prvy prvok s jeho velkostou
// Alokuje a nuluje bitove pole

#define bitset_free(jmeno_pole)  \
    free(jmeno_pole);            \
    jmeno_pole = NULL

#ifdef USE_INLINE
// pouzivanie inline funkcii, rovnaka funkcia ako u makier

#include "error.h"

inline bitset_index_t bitset_size(bitset_t jmeno_pole){
    return jmeno_pole[0] * B_ULONG;
    }

inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, _Bool vyraz){
    bitset_index_t mez = (jmeno_pole[0]-1) * B_ULONG;  \
    if((long) index < 0 || (long) index > (long) mez){         \
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)mez); \
    }
    index += B_ULONG;
    if(vyraz){
        jmeno_pole[index/B_ULONG] = jmeno_pole[index/B_ULONG] | (~(~ (unsigned) 0 << 1)) << index % B_ULONG;
    }
    else{
        jmeno_pole[index/B_ULONG] = jmeno_pole[index/B_ULONG] & ~(~(~ (unsigned) 0 << 1) << index % B_ULONG);
    }
}

inline _Bool bitset_getbit(bitset_t jmeno_pole, bitset_index_t index){
    bitset_index_t mez = (jmeno_pole[0]-1) * B_ULONG;
    if ((long) index < 0 || (long) index > (long) mez) {
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)mez);
    }
    return (jmeno_pole[index/B_ULONG+1] >> index % B_ULONG & ~(~ (unsigned) 0 << 1));
}

#else
#define bitset_size(jmeno_pole) \
    jmeno_pole[0] * B_ULONG

#define bitset_setbit(jmeno_pole, index, vyraz) \
    do{                                            \
    bitset_index_t _tmp = index + B_ULONG;      \
    bitset_index_t _mez = (jmeno_pole[0]-1) * B_ULONG;  \
    if((long) index < 0 || (long) index > (long) _mez){         \
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)_mez); \
    }                                        \
    if(vyraz){                                   \
        jmeno_pole[_tmp/B_ULONG] = jmeno_pole[_tmp/B_ULONG] | (~(~ (unsigned) 0 << 1)) << _tmp % B_ULONG;  \
    }                                            \
    else{                                        \
        jmeno_pole[_tmp/B_ULONG] = jmeno_pole[_tmp/B_ULONG] & ~(~(~ (unsigned) 0 << 1) << _tmp % B_ULONG); \
    } \
    }while(0)
// Nastavuje zadany bit na urcitu hodnotu

#define bitset_getbit(jmeno_pole, index) \
    ((long) index < 0 || (long) index > (long) (jmeno_pole[0]-1) * B_ULONG )?                                     \
    error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)(jmeno_pole[0]-1) * B_ULONG), 0:\
    (jmeno_pole[index/B_ULONG+1] >> index % B_ULONG & ~(~ (unsigned) 0 << 1))\
// Vracia hodnotu daneho bitu

#endif  //USE_INLINE
#endif //IJC_BITSET_H
