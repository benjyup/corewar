/*
** my_args_are_valid.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Tue Mar 22 15:35:00 2016 vincent mesquita
** Last update Sat Mar 26 21:40:36 2016 Vincent Florian
*/

#include <stdlib.h>
#include "asm.h"

int		my_check_args_number(char **wordtab,
				     t_op *op,
				     t_file_info *fi)
{
  int		i;

  i = 0;
  if (wordtab == NULL)
    {
      my_put_error("Asm", fi, "Invalid argument number\n");
      return (0);
    }
  while (wordtab[i] != NULL)
    i += 1;
  if (i != op->nbr_args)
    {
      my_put_error("Asm", fi, "Invalid argument number\n");
      return (0);
    }
  return (1);
}

int		my_args_are_valid(char **wordtab,
				  t_op *op,
				  t_file_info *fi)
{
  int		i;
  int		args;

  i = 0;
  if (!my_check_args_number(wordtab, op, fi))
    return (0);
  while (i < op->nbr_args)
    {
      args = 0;
      if (wordtab[i][0] == 'r')
	args = (args | T_REG);
      else if (wordtab[i][0] == DIRECT_CHAR)
	args = (args | T_DIR);
      else if ((wordtab[i][0] >= '0' && wordtab[i][0] <= '9')
	       || wordtab[i][0] == '-')
	args = (args | T_IND);
      if ((args & op->type[i]) != args || args == 0)
	{
	  my_put_error("Asm", fi, "Invalid argument\n");
	  return (0);
	}
      i += 1;
    }
  return (1);
}
