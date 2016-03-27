/*
** my_check_sti.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Mar 24 14:46:44 2016 vincent mesquita
** Last update Sat Mar 26 22:00:52 2016 vincent mesquita
*/

#include "asm.h"

static int		my_sti_w(char **wordtab,
				 t_file_info *fi,
				 unsigned char args[MAX_ARGS_NUMBER])
{
  if (my_write_register(wordtab[0], fi) == -1)
    return (-1);
  if (my_write_index(args[1], wordtab[1], fi) == -1)
    return (-1);
  if (my_write_index(args[2], wordtab[2], fi) == -1)
    return (-1);
  return (0);
}

int			my_check_sti(char **wordtab,
				     t_header *header,
				     t_file_info *fi)
{
  int			index_op;
  unsigned char		byte_code;
  unsigned char		args[MAX_ARGS_NUMBER];

  (void)(header);
  if ((index_op = my_get_op(wordtab[0])) == -1)
    return (-1);
  if (!my_args_are_valid(&wordtab[1], &op_tab[index_op], fi))
    return (-1);
  my_fill_args(args, &wordtab[1]);
  byte_code = my_byte_code(args);
  if (my_write(fi->fd, &op_tab[index_op].code, 1) != 1
      || my_write(fi->fd, &byte_code, 1) != 1
      || my_sti_w(&wordtab[1], fi, args) == -1)
    return (-1);
  fi->code_put = 1;
  return (0);
}
