cc = gcc
flags = -Wall -ansi -pedantic -std=c90
NAME = permut

objects = permut.o

$(NAME): clean $(objects)
	$(cc) $(objects) -o $(NAME)

$(objects): %.o: %.c
	$(cc) -c $(flags) $< -o $@

clean:
	rm -f $(NAME) *.o *.i *.s *.bc