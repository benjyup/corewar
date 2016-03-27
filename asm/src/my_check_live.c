/*
** my_check_live.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Mar 21 14:18:25 2016 vincent mesquita
** Last update Sat Mar 26 22:03:13 2016 vincent mesquita
*/

#include <stdlib.h>
#include "asm.h"

int		my_check_live(char **wordtab,
			      t_header *header,
			      t_file_info *fi)
{
  int		index_op;
  int		nbr;

  (void)(header);
  if ((index_op = my_get_op(wordtab[0])) == -1)
    return (-1);
  if (!my_args_are_valid(&wordtab[1], &op_tab[index_op], fi))
    return (-1);
  if ((nbr = my_get_dir(wordtab[1], fi, 0)) == -1)
    return (-1);
  if (my_write(fi->fd, &op_tab[index_op].code, 1) != 1
      || my_write(fi->fd, &nbr, 4) != 4)
    return (-1);
  fi->code_put = 1;
  return (0);
}
