/*
** my_epure_tabulation.c<2> for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Mar 17 16:23:25 2016 vincent mesquita
** Last update Thu Mar 24 17:28:51 2016 Vincent Florian
*/

#include <stdlib.h>
#include "asm.h"

void		my_epure_tabulation(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i])
    {
      if (str[i] == SEPARATOR_CHAR)
	str[i] = ' ';
      if (str[i] == '\t')
	str[i] = ' ';
      i += 1;
    }
}
