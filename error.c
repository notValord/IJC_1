// error.c
// Řešení IJC-DU1, příklad b), 20.3.2021
// Autor: Veronika Molnárová, xmolna08, FIT-1BIT
// Přeloženo: gcc 9.3
// Definicie error funkcii s premennym poctom premennych

#include "error.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void warning_msg(const char *fmt, ...){  //vypisuje error_msg vo forme printf
    fprintf(stderr, "CHYBA: ");
    va_list list;
    va_start(list, fmt);
    vfprintf(stderr, fmt, list);
    va_end(list);
}

void error_exit(const char *fmt, ...){  //vypisuje error_msg vo forme printf a ukonci program
    fprintf(stderr, "CHYBA: ");
    va_list ex_list;
    va_start(ex_list, fmt);
    vfprintf(stderr, fmt, ex_list);
    va_end(ex_list);
    exit(1);
}
