/*
** my_get_dir.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Wed Mar 23 14:20:26 2016 vincent mesquita
** Last update Sun Mar 27 20:14:26 2016 Vincent Florian
*/

#include <stdlib.h>
#include <limits.h>
#include "asm.h"

int		my_line_is_not_empty(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (1);
      i += 1;
    }
  return (0);
}

int		my_get_reg(char *str, t_file_info *fi)
{
  int		nbr;

  if ((nbr = my_getnbr(str)) < 1 || nbr > REG_NUMBER)
    {
      my_put_error("Asm", fi, "Invalid register number\n");
      return (-1);
    }
  return (nbr);
}

static int	mine_is_a_label_dir(char *str)
{
  if (my_strlen(str) > 2
      && str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR)
    return (1);
  return (0);
}

int		my_get_dir(char *str, t_file_info *fi, int flag_idx)
{
  long		check_nbr;
  int		nbr;

  if (mine_is_a_label_dir(str))
    {
      if (fi->label == NULL)
	return (-1);
      nbr = fi->label->next->pos;
      my_delete_to_begin_int_list(fi->label);
      if (flag_idx == 1)
	return (my_endian_short(nbr));
      else
	return (my_endian(nbr));
    }
  else
    {
      if ((check_nbr = my_getnbr_long(str)) < INT_MIN || nbr > INT_MAX)
	my_put_warning("Asm", fi, "Direct too big\n");
      if (flag_idx == 1)
	nbr = my_endian_short(my_getnbr(str));
      else
	nbr = my_endian(my_getnbr(str));
    }
  return (nbr);
}
