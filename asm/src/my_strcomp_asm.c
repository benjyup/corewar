/*
** my_strcomp_asm.c<2> for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Mar 17 16:23:51 2016 vincent mesquita
** Last update Fri Mar 25 11:41:47 2016 vincent mesquita
*/

#include <string.h>
#include "asm.h"

int		my_strcomp_asm(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (op_tab[i].mnemonique != NULL)
    {
      if (my_strcomp(str, op_tab[i].mnemonique) == 1)
	return (1);
      i += 1;
    }
  return (0);
}

int		my_get_op(char *instruction)
{
  int		i;

  if (instruction == NULL)
    return (0);
  i = 0;
  while (op_tab[i].mnemonique != NULL)
    {
      if (my_strcomp(instruction, op_tab[i].mnemonique) == 1)
	return (i);
      i += 1;
    }
  return (-1);
}
