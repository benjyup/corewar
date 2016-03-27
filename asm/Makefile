##
## Makefile for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
##
## Made by vincent mesquita
## Login   <mesqui_v@epitech.net>
##
## Started on  Thu Mar 17 16:21:56 2016 vincent mesquita
## Last update Sun Mar 27 21:17:28 2016 Vincent Florian
##

NAME		=	asm

CC		=	gcc

RM		=	rm -rf

CFLAGS		+=	-W -Wall -Wextra -I../include

SRCS		=	../Basics/my_puterror.c		\
			../Basics/my_put_error.c	\
			../Basics/my_getnbr.c		\
			../Basics/my_putchar.c		\
			../Basics/my_putstr.c		\
			../Basics/my_put_nbr.c		\
			../Basics/my_strlen.c		\
			../Basics/my_strcat.c		\
			../Basics/my_strcat_char.c	\
			../Basics/my_strcpy.c		\
			../Basics/my_strcomp.c		\
			../Basics/get_next_line.c	\
			../Basics/my_str_to_wordtab.c	\
			../Basics/my_show_wordtab.c	\
			../Basics/my_add_to_wordtab.c	\
			../Basics/my_delete_to_wordtab.c\
			../Basics/my_free_wordtab.c	\
			../Basics/my_wordtab_cpy.c	\
			../Basics/my_wordtab_len.c	\
			./src/mine_is_a_comment.c	\
			./src/my_main_label.c		\
			./src/init_label.c		\
			./src/my_get_ind.c		\
			./src/my_init_list_fonction.c	\
			./src/pars_label.c		\
			./src/my_get_dir.c		\
			./src/my_writes.c		\
			./src/my_asm.c			\
			./src/my_list_fonction.c	\
			./src/my_check_label.c		\
			./src/my_ps.c			\
			./src/my_strcomp_asm.c		\
			./src/my_epure_str.c		\
			./src/my_epure_tabulation.c	\
			./src/main.c			\
			./src/my_strcat2.c		\
			./src/my_fill_tab.c		\
			./src/my_check_live.c		\
			./src/my_check_comment.c	\
			./src/my_check_name.c		\
			./src/my_check_ld.c		\
			./src/my_check_st.c		\
			./src/my_check_add.c		\
			./src/my_check_sub.c		\
			./src/my_check_and.c		\
			./src/my_check_or.c		\
			./src/my_check_xor.c		\
			./src/my_check_zjmp.c		\
			./src/my_check_ldi.c		\
			./src/my_check_sti.c		\
			./src/my_check_fork.c		\
			./src/my_check_lld.c		\
			./src/my_check_lldi.c		\
			./src/my_check_lfork.c		\
			./src/my_check_aff.c		\
			./src/my_endian.c		\
			./src/my_args_are_valid.c	\
			./src/my_byte_code.c		\
			./src/op.c

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
