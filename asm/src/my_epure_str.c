/*
** my_epure_str.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Mar 25 12:20:18 2016 vincent mesquita
** Last update Sun Mar 27 20:18:43 2016 Vincent Florian
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
