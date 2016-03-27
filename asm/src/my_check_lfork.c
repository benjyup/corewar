/*
** my_check_lfork.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Mar 24 16:15:00 2016 vincent mesquita
** Last update Sat Mar 26 14:51:46 2016 vincent mesquita
*/

#include "asm.h"

static int		my_lfork_w(char **wordtab,
				   t_file_info *fi,
				   unsigned char args[MAX_ARGS_NUMBER])
{
  if (my_write_index(args[0], wordtab[0], fi) == -1)
    return (-1);
  return (0);
}

int			my_check_lfork(char **wordtab,
				       t_header *header,
				       t_file_info *fi)
{
  int			index_op;
  unsigned char		args[MAX_ARGS_NUMBER];

  (void)(header);
  if ((index_op = my_get_op(wordtab[0])) == -1)
    return (-1);
  if (!my_args_are_valid(&wordtab[1], &op_tab[index_op], fi))
    return (-1);
  my_fill_args(args, &wordtab[1]);
  if (my_write(fi->fd, &op_tab[index_op].code, 1) != 1
      || my_lfork_w(&wordtab[1], fi, args) == -1)
    return (-1);
  return (0);
}
