/*
** my_delete_label.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Mar 25 14:39:58 2016 vincent mesquita
** Last update Fri Mar 25 15:03:23 2016 vincent mesquita
*/

#include <stdlib.h>
#include "asm.h"

char		**my_delete_label(char **wordtab)
{
  char		**cpy;

  cpy = NULL;
  if (wordtab == NULL || wordtab[0] == NULL)
    return (NULL);
  if (mine_is_a_label(wordtab[0]))
    {
      if ((cpy = my_delete_to_wordtab(wordtab, 0)) == NULL)
	return (NULL);
      my_free_wordtab(wordtab);
      return (cpy);
    }
  return (wordtab);
}
