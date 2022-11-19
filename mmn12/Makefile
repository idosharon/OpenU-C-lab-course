cc = gcc
flags = -Wall -ansi -pedantic 
NAME = my_bcmp

make: *.c
	$(cc) *.c -o $(NAME) $(flags)

run: make
	./$(NAME)

clean:
	rm -f $(NAME) *.o