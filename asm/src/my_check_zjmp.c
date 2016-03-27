/*
** my_check_zjmp.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Mar 24 12:43:44 2016 vincent mesquita
** Last update Sat Mar 26 22:03:48 2016 Vincent Florian
*/

#include "asm.h"

static int		my_zjmp_write(char *str, t_file_info *fi)
{
  short			nbr;

  if ((nbr = my_get_dir(str, fi, 1)) == -1)
    return (-1);
  if (my_write(fi->fd, &nbr, IND_SIZE) != IND_SIZE)
    return (-1);
  return (0);
}

int			my_check_zjmp(char **wordtab,
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
      || my_zjmp_write(wordtab[1], fi) == -1)
    return (-1);
  fi->code_put = 1;
  return (0);
}
