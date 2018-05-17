NAME = fillit

HEADER = libft.h

CONVC = $(SRC:.c=.o)

SRC = check.c \
	  main.c \
	  map.c \
	  print.c \
	  resolve.c \
	  resolve_two.c \

all : $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)

clean:
	rm -rf $(CONVC)
fclean:
	rm -rf $(CONVC) $(NAME)

re: fclean all

.PHONY : all clean re fclean
