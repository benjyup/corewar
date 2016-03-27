/*
** stock.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar/corewar/src
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Mar 17 13:45:50 2016 Timothée Puentes
** Last update Sat Mar 26 15:20:34 2016 Peixoto Benjamin
*/

#include "corewar.h"

void		stock_in(unsigned char *mem, char *inst,
			 int offset, int size)
{
  int		c;

  c = 0;
  while (c < size)
    {
      mem[get_real_pos(offset + c)] = inst[c];
      c++;
    }
}

void		stock_offset(t_mem *mem, int nb_champ)
{
  int		c;
  int		offset;
  int		i;

  i = 0;
  c = 0;
  while (c < MAX_CHAMP)
    {
      if (mem->champ[c].number != -1)
	{
	  if (mem->champ[c].offset != -1)
	    offset = mem->champ[c].offset;
	  else
	    offset = MEM_SIZE * (++i) / nb_champ;
	  add_process(mem, mem->champ[c].number, offset);
	  stock_in(mem->box, mem->champ[c].tmp,
		   offset , mem->champ[c].size_ins);
	}
      c++;
    }
}

int		choose_place(t_mem *mem)
{
  int		c;
  int		champ_nb;

  champ_nb = 0;
  c = 0;
  while (c < MAX_CHAMP)
    {
      if (mem->champ[c].number != -1)
	champ_nb += 1;
      c++;
    }
  if (champ_nb == 0)
    return (1);
  stock_offset(mem, champ_nb);
  return (0);
}
