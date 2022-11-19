cc = gcc
flags = -Wall -ansi -pedantic

my_rottate: my_rottate.o rottate.o
	$(cc) $(flags) -o my_rottate my_rottate.o rottate.o

my_rottate.o: my_rottate.c
	$(cc) $(flags) -c my_rottate.c

rottate.o: rottate.c rottate.h
	$(cc) $(flags) -c rottate.c