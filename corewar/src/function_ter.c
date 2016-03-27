/*
** function_ter.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar/corewar
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Mar 21 15:59:25 2016 Timothée Puentes
** Last update Fri Mar 25 16:38:56 2016 Timothée Puentes
*/

#include <stdio.h>
#include "asm.h"
#include "my_basics.h"

int		st(t_mem *mem, t_process *proc)
{
  int		op_code;
  int		reg;
  int		rank;

  op_code = mem->box[(proc->act + 1) % MEM_SIZE];
  reg = mem->box[(proc->act + 2) % MEM_SIZE] - 1;
  if (reg < 0 || reg > REG_NUMBER)
    return (0);
  if (get_type(op_code, 1) == T_REG)
    {
      rank = mem->box[(proc->act + 3) % MEM_SIZE] - 1;
      if (rank < 0 || rank > REG_NUMBER)
	return (0);
      proc->reg[rank] = proc->reg[reg];
      return (0);
    }
  rank = (short)read_n_char_at_x(mem, IND_SIZE, proc->act + 3) % MEM_SIZE;
  store_n_char_at_x(mem, proc->reg[reg], DIR_SIZE, proc->act + rank);
  return (0);
}

int		ld(t_mem *mem, t_process *proc)
{
  int		op_code;
  int		type;
  int		res;
  int		rank;

  op_code = mem->box[(proc->act + 1) % MEM_SIZE];
  type = get_type(op_code, 0);
  if (type == T_DIR)
    res = read_n_char_at_x(mem, DIR_SIZE, proc->act + 2);
  else if (type == T_IND)
    {
      res = (short)read_n_char_at_x(mem, IND_SIZE, proc->act + 2);
      res = read_n_char_at_x(mem, DIR_SIZE,
			     get_real_pos((proc->pc + res) % IDX_MOD));
    }
  rank = read_n_char_at_x(mem, 1, proc->act + 2 + LD_SIZE) - 1;
  if (rank < 0 || rank > REG_NUMBER)
     return (proc->carry = 0);
  proc->carry = 1;
  proc->reg[rank] = res;
  return (0);
}

int		lld(t_mem *mem, t_process *proc)
{
  int		op_code;
  int		type;
  int		res;
  int		rank;

  op_code = mem->box[(proc->act + 1) % MEM_SIZE];
  type = get_type(op_code, 0);
  if (type == T_DIR)
    res = read_n_char_at_x(mem, DIR_SIZE, proc->act + 2);
  else if (type == T_IND)
    {
      res = (short)read_n_char_at_x(mem, IND_SIZE, proc->act + 2);
      res = read_n_char_at_x(mem, DIR_SIZE,
			     get_real_pos(proc->pc + res));
    }
  rank = read_n_char_at_x(mem, 1, proc->act + 2 + LD_SIZE) - 1;
  if (rank < 0 || rank > REG_NUMBER)
     return (proc->carry = 0);
  proc->carry = 1;
  proc->reg[rank] = res;
  return (0);
}
