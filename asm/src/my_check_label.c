/*
** my_check_label.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sat Mar 26 22:04:12 2016 vincent mesquita
** Last update Sat Mar 26 22:04:14 2016 vincent mesquita
*/

#include <stdlib.h>
#include "asm.h"

static int	valid_label_char(char c)
{
  int		i;

  i = 0;
  while (LABEL_CHARS[i])
    {
      if (c == LABEL_CHARS[i])
	return (1);
      i += 1;
    }
  return (0);
}

int		my_check_label(t_label *current, t_first *first, int i)
{
  t_file_info	fi;
  char		*wordtab;

  wordtab = current->label;
  fi.filename = first->filename;
  fi.line_nbr = current->line;
  if (wordtab[0] == '%' && wordtab[1] == ':')
    i = 2;
  while (wordtab[++i])
    {
      if (wordtab[i] == LABEL_CHAR && !wordtab[i + 1])
	break ;
      else if (!valid_label_char(wordtab[i]))
	{
	  my_put_error("asm", &fi, "Label Invalid\n");
	  return (-1);
	}
    }
  if (wordtab[i] != LABEL_CHAR && wordtab[0] != '%')
    {
      my_put_error("asm", &fi, "Label Invalid\n");
      return (-1);
    }
  return (0);
}

int		mine_is_a_label(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = -1;
  while (str[++i])
    {
      if (str[i] == LABEL_CHAR && !str[i + 1])
	break ;
      else if (!valid_label_char(str[i]))
	return (0);
    }
  if (str[i] != LABEL_CHAR || my_strlen(str) == 1)
    return (0);
  return (1);
}
