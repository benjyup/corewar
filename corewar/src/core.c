/*
** core.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Mar 16 12:12:05 2016 Timothée Puentes
** Last update Fri Mar 25 12:20:50 2016 Timothée Puentes
*/

#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"

int		still_alive(t_mem *mem)
{
  int		c;
  int		nb_alive;

  c = 0;
  nb_alive = 0;
  while (c < MAX_CHAMP)
    {
      if (mem->champ[c].number != -1 && mem->champ[c].live == ALIVE)
	{
	  mem->champ[c].live = SCHRODINGER;
	  nb_alive += 1;
	}
      else
	mem->champ[c].live = DEAD;
      c += 1;
    }
  return (nb_alive);
}

int		get_inst(t_mem *mem, t_process *proc)
{
  int		c;

  c = 0;
  if ((proc->instruc = malloc(sizeof(t_op))) == NULL)
    return (1);
  while (op_tab[c].nbr_cycles != 0)
    {
      if (op_tab[c].code == mem->box[(proc->act) % MEM_SIZE])
	{
	  *proc->instruc = op_tab[c];
	  return (0);
	}
      c++;
   }
  *proc->instruc = op_tab[c];
  proc->instruc->nbr_cycles = 0;
  proc->pc = (proc->act + 1) % MEM_SIZE;
  return (0);
}

int		compute_procs(t_mem *mem)
{
  int		c;

  c = 0;
  while (c < mem->nb_proc)
    {
      if (mem->proc[c].instruc == NULL && get_inst(mem, &mem->proc[c]))
	return (1);
      get_pc(mem, &mem->proc[c]);
      if (mem->proc[c].instruc != NULL)
	{
	  if (mem->proc[c].instruc->nbr_cycles == 0)
	    {
	      if (use_a_function(mem, &mem->proc[c]))
		return (1);
	      free(mem->proc[c].instruc);
	      mem->proc[c].instruc = NULL;
	      mem->proc[c].act = get_real_pos(mem->proc[c].pc);
	    }
	  else
	    mem->proc[c].instruc->nbr_cycles -= 1;
	}
      c += 1;
    }
  return (0);
}

void		print_finish(t_mem *mem)
{
  int		c;

  c = 0;
  if (mem->last_alive == -1)
    my_putstr(DRAW);
  else
    while (c < MAX_CHAMP)
      {
	if (mem->champ[c].number == mem->last_alive)
	  print_live_victory(mem, 1, mem->last_alive);
	c += 1;
      }
  return ;
}

int		core(t_mem *mem)
{
  int		cycle;
  int		nb_alive;

  mem->cycle_to_die = CYCLE_TO_DIE;
  cycle = 0;
  nb_alive = 4;
  while (nb_alive > 1)
    {
      cycle++;
      if (cycle % mem->cycle_to_die == 0)
	nb_alive = still_alive(mem);
      if (compute_procs(mem))
	return (1);
      if (cycle == mem->cycle_to_dumping)
	{
	  if (dumping(mem))
	    return (1);
	  return (0);
	}
    }
  print_finish(mem);
  return (0);
}
