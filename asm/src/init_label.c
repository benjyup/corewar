/*
** init_label.c for init_label.c in /home/vincen_s/rendu/CPE_2015_corewar/asm
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Sun Mar 27 19:47:42 2016 Vincent Florian
** Last update Sun Mar 27 20:55:11 2016 Vincent Florian
*/

#include <stdlib.h>
#include "asm.h"

static void		init_tab(char *op, t_tab_op *ops, int i)
{
  ops->op = op;
  ops->o_cod = i;
}

void		init_struct(t_tab_op *tab)
{
  init_tab("live", &tab[0], 5);
  init_tab("zjmp", &tab[1], IND_SIZE + 1);
  init_tab("fork", &tab[2], IND_SIZE + 1);
  init_tab("lfork", &tab[3], IND_SIZE + 1);
  init_tab("aff", &tab[4], 3);
  init_tab("sti", &tab[5], 0);
  init_tab("ldi", &tab[6], 0);
  init_tab("lldi", &tab[7], 0);
}

int		my_check_name2(int *fd, int i)
{
  int		j;
  char		*line;
  char		**wordtab;

  j = 0;
  while ((line = get_next_line(*fd)) != NULL && i != 2)
    {
      if (line[0] != 0)
	{
	  my_epure_tabulation(line);
	  if ((wordtab = my_str_to_wordtab(line, ' ')) == NULL)
	    return (-1);
	  if (my_strcomp(wordtab[0], ".name") == 1 && i == 0)
	    i = 1;
	  if (my_strcomp(wordtab[0], ".comment") == 1 && i == 1)
	    i = 2;
	  j++;
	  my_free_wordtab(wordtab);
	  free(line);
	}
    }
  if (i != 2 || j != 2)
    return (-1);
  return (1);
}

int		my_strlen_wordtab(char **wordtab)
{
  int		i;
  int		j;

  j = 0;
  i = -1;
  while (wordtab[j] != NULL)
    j++;
  while (wordtab[0][++i] && wordtab[0][i] != LABEL_CHAR);
  if (wordtab[0][i] == LABEL_CHAR && wordtab[0][i + 1] == 0 && j == 1)
    return (2);
  else if (wordtab[0][i] == LABEL_CHAR && wordtab[0][i + 1] == 0)
    return (1);
  else
    return (-1);
}

void		my_args(unsigned char *args, char **wordtab, int j)
{
  int		i;

  i = 0;
  while (wordtab[i] != NULL && i < MAX_ARGS_NUMBER)
    {
      if (wordtab[i][0] == 'r')
	args[i] = REG_SIZE;
      else if (wordtab[i][0] == DIRECT_CHAR)
	args[i] = DIR_SIZE / j;
      else if ((wordtab[i][0] >= '0' && wordtab[i][0] <= '9')
	       || (wordtab[i][0] == '-' && wordtab[i][1] >= '0'
		   && wordtab[i][1] <= '9'))
	args[i] = IND_SIZE;
      else
	args[i] = 0;
      i += 1;
    }
  while (i < MAX_ARGS_NUMBER)
    args[i++] = 0;
}
