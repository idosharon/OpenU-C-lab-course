cc = gcc
flags = -Wall -ansi -pedantic 
NAME = abc

make: *.c
	$(cc) -c *.c $(flags)
	$(cc) *.o -o $(NAME)

run: make
	./$(NAME)