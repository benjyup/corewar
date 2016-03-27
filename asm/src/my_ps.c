/*
** my_ps.c for my_ps.c in /home/vincen_s/rendu/CPE_2015_corewar/asm/src
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Tue Mar 22 17:40:33 2016 Vincent Florian
** Last update Sat Mar 26 21:41:43 2016 Vincent Florian
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"

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

void		init_tab(char *op, t_tab_op *ops, int i)
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

int		my_add_to_ps2(int *ps, t_tab_op tab[8],
			      char **wordtab, int j)
{
  int		i;
  unsigned char	args[MAX_ARGS_NUMBER];

  i = -1;
  while (++i < 8)
    if (my_strcomp(wordtab[j], tab[i].op) == 1)
      {
	*ps += tab[i].o_cod;
	break ;
      }
  if (i == 5 || i == 6 || i == 7)
    {
      my_args(args, &wordtab[j + 1], 2);
      i = -1;
      while (++i < MAX_ARGS_NUMBER)
	*ps += args[i];
      *ps += 2;
      return (0);
    }
  if (i == 8)
    {
      *ps += 2;
      return (j + 1);
    }
  return (0);
}

int		my_add_to_ps(int *ps, t_tab_op tab[8], char **wordtab)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (wordtab[i] != NULL)
    i++;
  if (i <= 1)
    return (i - 1);
  i = -1;
  while (wordtab[0][++i] != 0 && wordtab[0][i] != LABEL_CHAR);
  if (wordtab[0][i] == LABEL_CHAR)
    j++;
  return (my_add_to_ps2(ps, tab, wordtab, j));
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

void		my_check_label2(char **wordtab, t_tab_op tab[8],
				t_first *first, int line)
{
  int		i;
  int		j;
  int		h;
  unsigned char	c[MAX_ARGS_NUMBER];

  i = 0;
  h = first->ps;
  if ((j = my_strlen_wordtab(wordtab)) == 1)
    my_add_to_end_label_list(first->root, wordtab[0], h, line);
  else if (j == 2)
    {
      my_add_to_end_label_list(first->root, wordtab[0], h, line);
      return ;
    }
  if ((j = my_add_to_ps(&first->ps, tab, wordtab)) < 0)
    return ;
  if (j != 0)
    {
      my_args(c, &wordtab[j], 1);
      while (i < MAX_ARGS_NUMBER && c[i])
	first->ps += c[i++];
    }
  i = 0;
  while (wordtab[j] != NULL)
    {
      if (wordtab[j][i] == DIRECT_CHAR &&
	  wordtab[j][i + 1] == LABEL_CHAR)
	my_add_to_end_label_list(first->root, wordtab[j], h, line);
      j++;
    }
}

int		my_ps_and_label(char *line, t_tab_op tab[8], int *i, t_first *first)
{
  char		**wordtab;

  (*i)++;
  my_epure_str(line);
  if (line[0] != 0)
    {
      if ((wordtab = my_str_to_wordtab(line, ' ')) == NULL)
	return (-1);
      if (wordtab[0] != NULL)
	my_check_label2(wordtab, tab, first, *i);
      my_free_wordtab(wordtab);
      free(line);
    }
  return (0);
}

t_first		*my_ps(char *filename, int i)
{
  t_first	*first;
  int		fd;
  char		*line;
  t_tab_op	tab[8];

  if ((first = my_init_first_list()) == NULL ||
      (first->root = my_init_label_list()) == NULL ||
      (fd = open(filename, O_RDONLY)) == -1||
      (my_check_name2(&fd, 0)) == -1)
    return (NULL);
  init_struct(tab);
  while ((line = get_next_line(fd)) != NULL)
    if ((my_ps_and_label(line, tab, &i, first)) == -1)
      return (NULL);
  first->line = i;
  first->filename = filename;
  return (first);
}
