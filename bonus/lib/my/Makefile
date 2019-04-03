##
## EPITECH PROJECT, 2018
## bistro-matic
## File description:
## makefile
##
SRC		= 	get_next_line.c		\
			my_getnbr.c			\
			my_put_nbr.c		\
			my_putchar.c		\
			my_strcat.c			\
			my_strcmp.c			\
			my_strdup.c			\
			my_strlen.c			\
			my_strncpy.c		\
			str_to_tab.c        \
			my_strconcat.c      \
			my_revstr.c         \
			my_putstr.c         \
			base_converter.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS += -g -pedantic -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

re:		fclean all

fclean:		clean
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
