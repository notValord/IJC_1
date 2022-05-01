// error.h
// Řešení IJC-DU1, příklad b), 20.3.2021
// Autor: Veronika Molnárová, xmolna08, FIT-1BIT
// Přeloženo: gcc 9.3
// Deklaracia error funkcii s premennym poctom premennych

#ifndef IJC_ERROR_H
#define IJC_ERROR_H

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif //IJC_ERROR_H
