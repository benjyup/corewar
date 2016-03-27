##
## Makefile for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar
## 
## Made by vincent mesquita
## Login   <mesqui_v@epitech.net>
## 
## Started on  Sat Mar 26 10:29:32 2016 vincent mesquita
## Last update Sat Mar 26 10:35:02 2016 vincent mesquita
##

NAME	=	make

ASM	=	asm

COREWAR	=	corewar

MAKE	= 	make -C

all: $(NAME)

$(NAME):
	$(MAKE) ./$(ASM)
	$(MAKE) ./$(COREWAR)

clean:
	$(MAKE) ./$(ASM) clean
	$(MAKE) ./$(COREWAR) clean

fclean: clean
	$(MAKE) ./$(ASM) fclean
	$(MAKE) ./$(COREWAR) fclean

re:
	$(MAKE) ./$(ASM) re
	$(MAKE) ./$(COREWAR) re

.PHONY: all clean fclean re
