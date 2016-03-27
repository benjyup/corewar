/*
** my_byte_code.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Tue Mar 22 16:26:12 2016 vincent mesquita
** Last update Sun Mar 27 17:49:56 2016 vincent mesquita
*/

#include <stdlib.h>
#include "asm.h"

void		my_fill_args(unsigned char args[MAX_ARGS_NUMBER],
			     char **wordtab)
{
  int		i;

  i = 0;
  while (wordtab[i] != NULL && i < MAX_ARGS_NUMBER)
    {
      if (wordtab[i][0] == 'r')
	args[i] = REGISTRE;
      else if (wordtab[i][0] == DIRECT_CHAR)
	args[i] = DIRECT;
      else if ((wordtab[i][0] >= '0' && wordtab[i][0] <= '9')
	       || (wordtab[i][0] == '-'
		   && (wordtab[i][1] >= '0' && wordtab[i][1] <= '9')))
	args[i] = INDIRECT;
      else
	args[i] = 0;
      i += 1;
    }
  while (i < MAX_ARGS_NUMBER)
    args[i++] = 0;
}

unsigned char	my_byte_code(unsigned char args[MAX_ARGS_NUMBER])
{
  unsigned char byte_code;
  int		i;
  unsigned char	gap;

  byte_code = 0;
  gap = 6;
  i = -1;
  while (++i < MAX_ARGS_NUMBER)
    {
      byte_code = byte_code | (args[i] << gap);
      gap -= 2;
    }
  return (byte_code);
}
