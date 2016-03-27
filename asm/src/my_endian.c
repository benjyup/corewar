/*
** my_endian.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Tue Mar 22 15:05:05 2016 vincent mesquita
** Last update Sat Mar 26 21:57:25 2016 vincent mesquita
*/

#include "asm.h"

int			my_endian(int nbr)
{
  t_endian		nb;
  char			cpy;

  nb.nb = nbr;
  cpy = nb.c[0];
  nb.c[0] = nb.c[3];
  nb.c[3] = cpy;
  cpy = nb.c[1];
  nb.c[1] = nb.c[2];
  nb.c[2] = cpy;
  return (nb.nb);
}

int			my_endian_short(short nbr)
{
  t_endian_short	nb;
  char			cpy;

  nb.nb = nbr;
  cpy = nb.c[0];
  nb.c[0] = nb.c[1];
  nb.c[1] = cpy;
  return (nb.nb);
}
