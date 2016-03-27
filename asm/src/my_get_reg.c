/*
** my_get_reg.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Wed Mar 23 11:48:02 2016 vincent mesquita
** Last update Sat Mar 26 22:00:02 2016 Vincent Florian
*/

#include "asm.h"

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
