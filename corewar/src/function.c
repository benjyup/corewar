/*
** function.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar/corewar
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Mar 21 11:17:45 2016 Timothée Puentes
** Last update Fri Mar 25 12:19:34 2016 Timothée Puentes
*/

#include <stdio.h>
#include "asm.h"
#include "my_basics.h"

int		live(t_mem *mem, t_process *proc)
{
  int		nb_champ;
  int		c;

  nb_champ = read_n_char_at_x(mem, DIR_SIZE, proc->act + 1);
  c = 0;
  while (c < MAX_CHAMP)
    {
      if (mem->champ[c].number == nb_champ)
	{
	  print_live_victory(mem, 0, nb_champ);
	  mem->champ[c].live = LIVE;
	  mem->last_alive = nb_champ;
	  if ((mem->nb_live += 1) >= NBR_LIVE)
	    {
	      mem->nb_live = 0;
	      mem->cycle_to_die -= CYCLE_DELTA;
	    }
	  return (0);
	}
      c += 1;
    }
  return (0);
}

int		zjump(t_mem *mem, t_process *proc)
{
  short		new;

  if (proc->carry == 0)
    return (0);
  new = read_n_char_at_x(mem, IND_SIZE, proc->act + 1);
  proc->pc = get_real_pos(proc->act + (new % IDX_MOD));
  return (0);
}

int		aff(t_mem *mem, t_process *proc)
{
  int		pos;

  pos = mem->box[(proc->act + 2) % MEM_SIZE] - 1;
  if (pos < 0 || pos >= REG_NUMBER)
    return (0);
  my_putchar(proc->reg[pos]);
  return (0);
}

int		add(t_mem *mem, t_process *proc)
{
  int		one;
  int		two;
  int		res;

  one = mem->box[(proc->act + 2) % MEM_SIZE] - 1;
  two = mem->box[(proc->act + 3) % MEM_SIZE] - 1;
  res = mem->box[(proc->act + 4) % MEM_SIZE] - 1;
  if ((one < 0 || one >= REG_NUMBER) ||
      (two < 0 || two >= REG_NUMBER) ||
      (res < 0 || res >= REG_NUMBER))
    {
      proc->carry = 0;
      return (0);
    }
  proc->carry = 1;
  proc->reg[res] = proc->reg[one] + proc->reg[two];
  return (0);
}

int		sub(t_mem *mem, t_process *proc)
{
  int		one;
  int		two;
  int		res;

  one = mem->box[(proc->act + 2) % MEM_SIZE] - 1;
  two = mem->box[(proc->act + 3) % MEM_SIZE] - 1;
  res = mem->box[(proc->act + 4) % MEM_SIZE] - 1;
  if ((one < 0 || one >= REG_NUMBER) ||
      (two < 0 || two >= REG_NUMBER) ||
      (res < 0 || res >= REG_NUMBER))
    {
      proc->carry = 0;
      return (0);
    }
  proc->carry = 1;
  proc->reg[res] = proc->reg[one] - proc->reg[two];
  return (0);
}
