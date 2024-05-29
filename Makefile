SRC = main.c\
	$(shell find src/ -name '*.c')\

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Werror -Wall -Wextra

NAME = chip8

all: $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) sdl2-config --cflags --libs

clean:
	rm -f $(OBJ)
	find -name "*~" -delete -o -name "*#" -delete -o -name "#*" -delete
	-o -name "*.o" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

push:  fclean
	bash ./tools/push_that.sh

cs: fclean
	./tools/coding-style.sh . .
	cat -e coding-style-reports.log
	rm -f coding-style-reports.log

.PHONY: all clean fclean re
		push cs