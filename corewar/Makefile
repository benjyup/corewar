##
## Makefile<corewar> for  in /home/puente_t/rendu/CPE/CPE_2015_corewar
##
## Made by Timothée Puentes
## Login   <puente_t@epitech.net>
##
## Started on  Wed Mar 16 16:21:03 2016 Timothée Puentes
## Last update Sun Mar 27 21:18:07 2016 Vincent Florian
##

NAME	=	corewar

SRC	=	src/main.c \
		src/function.c \
		src/useful.c \
		src/function_bis.c \
		src/function_ter.c \
		src/function_quad.c \
		src/function_pent.c \
		src/init.c \
		src/stock.c \
		src/core.c \
		src/processus.c \
		src/print_error_etc.c \
		src/dumping.c \
		src/option.c \
		../Basics/my_put_error.c \
		../Basics/my_puterror.c \
		../Basics/my_putstr.c \
		../Basics/my_strlen.c \
		../Basics/my_strcpy.c \
		../Basics/my_put_nbr.c \
		../Basics/my_strcat.c \
		../Basics/my_putchar.c \
		../Basics/my_getnbr.c \
		../Basics/my_strcomp.c \
		src/op.c

OBJS	=	$(SRC:.c=.o)

CC	=	gcc -g -o

RM	=	rm -rf

CFLAGS	+=	-W -Wall -Wextra -I../include

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
