/*
** processus.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar/corewar
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Fri Mar 18 10:23:29 2016 Timothée Puentes
** Last update Fri Mar 25 16:35:49 2016 Timothée Puentes
*/

#include <stdio.h>
#include <stdlib.h>
#include "corewar.h"
#include "my_basics.h"

t_funct	functions[] =
  {
    {&live}, {&ld}, {&st}, {&add}, {&sub}, {&and},
    {&or}, {&xor}, {&zjump}, {&ldi}, {&sti},
    {&my_fork}, {&lld}, {&lldi},
    {&my_lfork}, {&aff}
  };

int		wrong_format(t_process *proc)
{
  proc->instruc->code = -1;
  proc->pc = (proc->act + 1) % MEM_SIZE;
  proc->instruc->nbr_cycles = 0;
  return (0);
}

int		get_type(int oc_code, int c)
{
  int		type;

  type = 1;
  while (type < 4)
    {
      if (type == ((oc_code >> ((MAX_ARGS_NUMBER - c) * 2 - 2)) % 4))
	break ;
      type += 1;
    }
  if (type >= 3)
    type += 1;
  return (type);
}

void		get_pc(t_mem *mem, t_process *proc)
{
  int		type;
  int		c;
  unsigned char	oc_code;

  if (LIVE || ZJUMP || FORK || LFORK)
    {
      proc->pc = (proc->act + 1 + NO_OC) % MEM_SIZE;
      return ;
    }
  oc_code = mem->box[(proc->act + 1) % MEM_SIZE];
  c = 0;
  proc->pc = (proc->act + 2) % MEM_SIZE;
  while (c < MAX_ARGS_NUMBER && proc->instruc->type[c] != 0)
    {
      type = get_type(oc_code, c);
      if (type == 5 || (type & proc->instruc->type[c]) == 0)
	{
	  wrong_format(proc);
	  return ;
	}
      proc->pc = proc->pc + GET_SIZE;
      c += 1;
    }
}

int		use_a_function(t_mem *mem, t_process *proc)
{
  if (proc->instruc->code < 1 || proc->instruc->code > 16)
    return (0);
  if (functions[(int)proc->instruc->code - 1].funct != NULL &&
      functions[(int)proc->instruc->code - 1].funct(mem, proc) == 1)
    return (1);
  return (0);
}
