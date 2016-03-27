/*
** my_get_ind.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Wed Mar 23 14:15:12 2016 vincent mesquita
** Last update Thu Mar 24 15:42:49 2016 vincent mesquita
*/

#include "asm.h"

int		my_get_ind(char *str, t_file_info *fi)
{
  int		nbr;

  if ((nbr = my_getnbr(str)) < (IDX_MOD * (-1))
      || nbr > IDX_MOD)
    my_put_warning("Asm", fi, "Indirection too far\n");
  nbr = my_endian_short((short)(nbr));
  return (nbr);
}
