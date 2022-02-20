##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC =    ./src/my_runner.c \
	 ./src/int_to_str.c \
	 ./src/help.c \
	 ./src/action_all_obj.c \
	 ./src/event.c \
	 ./src/win.c \
	 ./src/map.c \
	 ./src/manage_map.c \
	 ./src/player.c \
	 ./src/create_object.c \
	 ./src/score.c \
	 ./src/display_bg.c \
	 ./src/jump.c \
	 ./src/bomb.c \
	 ./src/piece.c \
	 ./src/monster.c \
	 ./src/collide.c \
	 ./src/skin.c \
	 ./src/home.c \
	 ./src/free.c \
	 ./src/handle_skin.c \
	 ./src/text_skin_menu.c \
	 ./src/music.c \
	 ./src/difficulty_menu.c \
	 ./src/high_score.c \
	 ./src/handle_main.c \
	 ./src/handle_home.c \
	 ./src/window.c

OBJ    =    $(SRC:.c=.o)

NAME   =    my_runner.exe

CFLAGS += -Wall -Wextra

all:    $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib_printf
	gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio -L./lib_printf -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
	fclean
	re
