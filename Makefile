##
## EPITECH PROJECT, 2018
## makefile
## File description:
## make
##

SRCS	=	src/change_map.c	\
		src/main.c	\
		src/matchstick.c	\
		src/my_put_array.c	\
		src/play_ia.c	\
		src/verif_entry.c	\
		src/display_player.c	\
		src/my_putstr.c	\
		src/my_strlen.c	\
		src/my_str_isnum.c	\
		src/my_putchar.c	\
		src/my_put_nbr.c	\
		src/my_getnbr.c	\
		src/get_next_line.c	\

OBJS	=	$(SRCS:.c=.o)

INCLUDE =	-I./includes/

CFLAGS	=	$(INCLUDE) -Wall -Wextra

NAME	=	matchstick

LIB	=	lib/my/

all:	$(NAME)

$(NAME):	$(OBJS)
		gcc -o $(NAME) $(OBJS)

clean:
		rm -f $(NAME)

fclean:		clean
		rm -f $(OBJS)

re:		fclean all
