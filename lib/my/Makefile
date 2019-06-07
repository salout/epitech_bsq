##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Task 01
##

SRC	=	my_putchar.c		\
		my_putstr.c			\
		my_strlen.c			\
		my_putstr_error.c	\
		my_str_to_word_array.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp libmy.a ../libmy.a
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../libmy.a

re:	fclean all

auteur:
	echo $(USER) > auteur
