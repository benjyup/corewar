/*
** useful.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar/corewar
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Mar 21 18:27:32 2016 Timothée Puentes
** Last update Wed Mar 23 13:35:49 2016 Timothée Puentes
*/

#include "corewar.h"

int		my_endian(int nbr)
{
  t_endian	nb;
  char		cpy;

  nb.nb = nbr;
  cpy = nb.c[0];
  nb.c[0] = nb.c[3];
  nb.c[3] = cpy;
  cpy = nb.c[1];
  nb.c[1] = nb.c[2];
  nb.c[2] = cpy;
  return (nb.nb);
}

int		my_power_it(int nb, int power)
{
  int		c;
  int		result;

  c = 0;
  result = 1;
  while (c != power)
    {
      result = result * nb;
      c++;
    }
  return (result);
}

int		get_real_pos(int pos)
{
  pos = pos % MEM_SIZE;
  while (pos < 0)
    pos += MEM_SIZE;
  return (pos);
}

int		read_n_char_at_x(t_mem *mem, int n, int x)
{
  int		res;
  int		c;
  int		place;

  res = 0;
  c = 0;
  while (c < n)
    {
      res = (res << 8);
      place = get_real_pos(x + c);
      res += mem->box[place];
      c += 1;
    }
  return (res);
}

int		store_n_char_at_x(t_mem *mem, int res, int n, int x)
{
  int		c;
  int		place;

  c = 0;
  while (c < n)
    {
      place = get_real_pos(x + c);
      mem->box[place] = res >> (8 * (n - 1));
      res = res << 8;
      c += 1;
    }
  return (res);
}
