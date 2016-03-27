/*
** my_check_or.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Mar 24 12:28:42 2016 vincent mesquita
** Last update Sat Mar 26 22:01:38 2016 vincent mesquita
*/

#include "asm.h"

int			my_check_or(char **wordtab,
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
      || my_cor_write(&wordtab[1], args, fi) == -1)
    return (-1);
  fi->code_put = 1;
  return (0);
}
