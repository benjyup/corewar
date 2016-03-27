/*
** my_epure_str.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Mar 25 12:20:18 2016 vincent mesquita
** Last update Sat Mar 26 13:45:47 2016 Vincent Florian
*/

#include <stdlib.h>
#include "asm.h"

static void	my_epure_comment(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == COMMENT_CHAR)
	{
	  str[i] = '\0';
	  return ;
	}
      i += 1;
    }
}

int		my_epure_str(char *str)
{
  if (str == NULL)
    return (-1);
  my_epure_comment(str);
  my_epure_tabulation(str);
  return (0);
}
