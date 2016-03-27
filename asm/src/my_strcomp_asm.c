/*
** my_strcomp_asm.c<2> for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Mar 17 16:23:51 2016 vincent mesquita
** Last update Sun Mar 27 20:08:57 2016 Vincent Florian
*/

#include <string.h>
#include "asm.h"

int	my_strcomp_label(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s2[i] && s2[i] != ':')
    {
      if (s1[i] != s2[i])
	return (-1);
      i++;
    }
  return (1);
}

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
