/*
** my_main_label.c for my_main_label.c in /home/vincen_s/rendu/CPE_2015_corewar/asm
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Sun Mar 27 19:53:12 2016 Vincent Florian
** Last update Sun Mar 27 20:31:04 2016 Vincent Florian
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"

t_first		*my_ps(char *filename, int i)
{
  t_first	*first;
  int		fd;
  char		*line;
  t_tab_op	tab[8];

  if ((first = my_init_first_list()) == NULL ||
      (first->root = my_init_label_list()) == NULL ||
      (fd = open(filename, O_RDONLY)) == -1 ||
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
