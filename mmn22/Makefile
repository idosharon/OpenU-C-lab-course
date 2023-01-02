cc = gcc
flags = -Wall -ansi -pedantic -std=c90
NAME = myset

objects = myset.o set.o command.o

$(NAME): $(objects)
	$(cc) $(objects) -o $(NAME)

$(objects): %.o: %.c
	$(cc) -c $(flags) $< -o $@

clean:
	rm -f $(NAME) *.o *.i *.s *.bc