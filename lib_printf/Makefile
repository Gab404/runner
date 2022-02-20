##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC =    ./sources/disp_stdarg.c \
	 ./sources/my_printf.c \
	 ./sources/disp_stdarg_2.c \
	 ./sources/fct_basic.c \
	 ./sources/fct_other.c \

OBJ    =    $(SRC:.c=.o)

NAME   =    libmy.a

all:    $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
	fclean
	re
