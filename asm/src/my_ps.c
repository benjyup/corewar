/*
** my_ps.c for my_ps.c in /home/vincen_s/rendu/CPE_2015_corewar/asm/src
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Tue Mar 22 17:40:33 2016 Vincent Florian
** Last update Sun Mar 27 20:57:18 2016 Vincent Florian
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"

static int	my_add_to_ps2(int *ps, t_tab_op tab[8],
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

static int	my_add_to_ps(int *ps, t_tab_op tab[8], char **wordtab)
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
  if (wordtab[j] == NULL)
    return (-1);
  return (my_add_to_ps2(ps, tab, wordtab, j));
}

static int	particulary_label(t_first *first,
				  t_tab_op tab[8],
				  char **wordtab)
{
  int		j;
  unsigned char	c[MAX_ARGS_NUMBER];
  int		i;

  i = 0;
  if ((j = my_add_to_ps(&first->ps, tab, wordtab)) < 0)
    return (-1);
  if (j != 0)
    {
      my_args(c, &wordtab[j], 1);
      while (i < MAX_ARGS_NUMBER && c[i])
	first->ps += c[i++];
    }
  return (j);
}

static void	my_check_label2(char **wordtab, t_tab_op tab[8],
				t_first *first, int line)
{
  int		i;
  int		j;
  int		h;

  i = 0;
  h = first->ps;
  if ((j = my_strlen_wordtab(wordtab)) == 1)
    my_add_to_end_label_list(first->root, wordtab[0], h, line);
  else if (j == 2)
    {
      my_add_to_end_label_list(first->root, wordtab[0], h, line);
      return ;
    }
  if ((j = particulary_label(first, tab, wordtab)) == -1)
    return ;
  i = 0;
  while (wordtab[j] != NULL)
    {
      if (wordtab[j][i] == DIRECT_CHAR &&
	  wordtab[j][i + 1] == LABEL_CHAR)
	my_add_to_end_label_list(first->root, wordtab[j], h, line);
      j++;
    }
}

int		my_ps_and_label(char *line, t_tab_op tab[8], int *i,
				t_first *first)
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
