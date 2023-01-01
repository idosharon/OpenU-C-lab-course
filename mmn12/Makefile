cc = gcc
flags = -Wall -ansi -pedantic -std=c90

my_bcmp: my_bcmp.o
	$(cc) $(flags) -o my_bcmp my_bcmp.o

my_bcmp.o: my_bcmp.c my_bcmp.h
	$(cc) $(flags) -c my_bcmp.c

clean: 
	rm -rf *.o my_bcmp .vscode .DS_Store