##
## EPITECH PROJECT, 2018
## bistro-matic
## File description:
## makefile
##
SRC		= 	$(wildcard src/*.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	navy

MY_PATH =	-Llib/my

CFLAGS += -g -pedantic -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(OBJ) -L"lib/my" -lmy $(CFLAGS)

clean:
		make -C ./lib/my clean
		rm -rf $(OBJ)

re:		fclean all
		make -C ./lib/my re

fclean:		clean
			make -C ./lib/my fclean
			rm -rf $(NAME)

push:	fclean
		git add -u
		git commit -m "$(shell curl --silent --fail https://whatthecommit.com/index.txt)"
		git push

push_all:	fclean
		git add -A
		git commit -m "$(shell curl --silent --fail https://whatthecommit.com/index.txt)"
		git push

.PHONY:		all clean fclean re
