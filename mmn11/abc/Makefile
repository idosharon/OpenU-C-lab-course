cc = gcc
flags = -Wall -ansi -pedantic

abc: abc.o shorten.o
	$(cc) $(flags) -o abc abc.o shorten.o

shorten.o: shorten.c shorten.h
	$(cc) $(flags) -c shorten.c

abc.o: abc.c abc.h
	$(cc) $(flags) -c abc.c