/*
** function_bis.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar/corewar
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Mar 21 12:36:50 2016 Timothée Puentes
** Last update Fri Mar 25 16:38:12 2016 Timothée Puentes
*/

#include <stdlib.h>
#include "asm.h"
#include "my_basics.h"

int		my_fork(t_mem *mem, t_process *proc)
{
  int		i;
  int		c;
  t_process	*new;
  int		idx;

  idx = read_n_char_at_x(mem, DIR_SIZE, proc->act + 1) % MEM_SIZE;
  if ((new = malloc(sizeof(t_process) * (mem->nb_proc + 2))) == NULL)
    return (1);
  proc->carry = 0;
  c = -1;
  while (++c < mem->nb_proc)
    new[c] = mem->proc[c];
  i = -1;
  while ((i += 1) < REG_NUMBER)
    new[c].reg[i] = proc->reg[i];
  new[c].cycle = 0;
  new[c].carry = 1;
  new[c].act = get_real_pos(proc->act + (idx % IDX_MOD));
  new[c].instruc = NULL;
  free(mem->proc);
  mem->proc = new;
  mem->nb_proc += 1;
  return (0);
}

int		my_lfork(t_mem *mem, t_process *proc)
{
  int		i;
  int		c;
  t_process	*new;
  int		idx;

  idx = read_n_char_at_x(mem, DIR_SIZE, proc->act + 1) % MEM_SIZE;
  if ((new = malloc(sizeof(t_process) * (mem->nb_proc + 2))) == NULL)
    return (1);
  proc->carry = 0;
  c = -1;
  while (++c < mem->nb_proc)
    new[c] = mem->proc[c];
  i = -1;
  while ((i += 1) < REG_NUMBER)
    new[c].reg[i] = proc->reg[i];
  new[c].cycle = 0;
  new[c].carry = 1;
  new[c].act = get_real_pos(proc->act + (idx));
  new[c].instruc = NULL;
  free(mem->proc);
  mem->proc = new;
  mem->nb_proc += 1;
  return (0);
}
