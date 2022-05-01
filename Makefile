# -*- Makefile -*-
#  Veronika Molnarova, FIT
#  IJC, DU-1
CC = gcc
CFLAGS = -O2 -g -std=c11 -pedantic -Wall -Wextra

#build always
all: primes primes-i steg-decode

run: primes primes-i
	ulimit -s 50000 && ./primes
	ulimit -s 50000 && ./primes-i

primes: primes.o eratosthenes.o error.o
	$(CC)  $(CFLAGS) primes.o eratosthenes.o error.o -o primes -lm

primes-i: primes-i.o eratosthenes-i.o error.o bitset.o
	$(CC) $(CFLAGS) -DUSE_INLINE primes-i.o eratosthenes-i.o error.o bitset.o -o primes-i -lm

steg-decode: steg-decode.o error.o ppm.o eratosthenes.o
	$(CC) $(CFLAGS) steg-decode.o error.o ppm.o eratosthenes.o -o steg-decode -lm

bitset.o: bitset.c bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c bitset.c -o bitset.o

eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

eratosthenes-i.o: eratosthenes.c eratosthenes.h bitset.h bitset.c error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o

error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c -o error.o

primes.o: primes.c bitset.h eratosthenes.h error.h
	$(CC) $(CFLAGS) -c primes.c -o primes.o

primes-i.o: primes.c bitset.h bitset.c eratosthenes.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

ppm.o: ppm.c ppm.h error.h
	$(CC) $(CFLAGS) -c ppm.c -o ppm.o

steg-decode.o: steg-decode.c error.h ppm.h bitset.h eratosthenes.h
	$(CC) $(CFLAGS) -c steg-decode.c -o steg-decode.o	
	

clean:
	rm -f *.o primes primes-i steg-decode
