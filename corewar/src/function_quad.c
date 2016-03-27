/*
** function_quad.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar/corewar
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Tue Mar 22 13:47:48 2016 Timothée Puentes
** Last update Fri Mar 25 11:57:33 2016 Timothée Puentes
*/

#include "corewar.h"
#include "my_basics.h"

int		get_res_for_type(t_mem *mem, t_process *proc, int place, int *type)
{
  int		res;

  res = 0;
  if (*type == T_DIR)
    res = read_n_char_at_x(mem, DIR_SIZE, place);
  else if (*type == T_IND)
    {
      res = (short)read_n_char_at_x(mem, IND_SIZE, place);
      res = read_n_char_at_x(mem, DIR_SIZE,
			     get_real_pos(proc->act + (res % IDX_MOD)));
    }
  else if (*type == T_REG)
    {
      res = mem->box[place % MEM_SIZE] - 1;
      if (res < 0 || res > REG_NUMBER)
	{
	  *type = -1;
	  return (0);
	}
      res = proc->reg[res];
    }
  return (res);
}

int		and(t_mem *mem, t_process *proc)
{
  int		op_code;
  int		type;
  int		place;
  int		one;
  int		two;

  op_code = mem->box[(proc->act + 1) % MEM_SIZE];
  type = get_type(op_code, 0);
  place = proc->act + 2;
  one = get_res_for_type(mem, proc, place, &type);
  if (type == -1)
    return (proc->carry = 0);
  place += GET_SIZE;
  type = get_type(op_code, 1);
  two = get_res_for_type(mem, proc, place, &type);
  if (type == -1)
    return (proc->carry = 0);
  place += GET_SIZE;
  place = mem->box[place % MEM_SIZE] - 1;
  if (place < 0 || place > REG_NUMBER)
    return (proc->carry = 0);
  proc->reg[place] = one & two;
  proc->carry = 1;
  return (0);
}

int		or(t_mem *mem, t_process *proc)
{
  int		op_code;
  int		type;
  int		place;
  int		one;
  int		two;

  op_code = mem->box[(proc->act + 1) % MEM_SIZE];
  type = get_type(op_code, 0);
  place = proc->act + 2;
  one = get_res_for_type(mem, proc, place, &type);
  if (type == -1)
    return (proc->carry = 0);
  place += GET_SIZE;
  type = get_type(op_code, 1);
  two = get_res_for_type(mem, proc, place, &type);
  if (type == -1)
    return (proc->carry = 0);
  place += GET_SIZE;
  place = mem->box[place % MEM_SIZE] - 1;
  if (place < 0 || place > REG_NUMBER)
    return (proc->carry = 0);
  proc->reg[place] = one | two;
  proc->carry = 1;
  return (0);
}

int		xor(t_mem *mem, t_process *proc)
{
  int		op_code;
  int		type;
  int		place;
  int		one;
  int		two;

  op_code = mem->box[(proc->act + 1) % MEM_SIZE];
  type = get_type(op_code, 0);
  place = proc->act + 2;
  one = get_res_for_type(mem, proc, place, &type);
  if (type == -1)
    return (proc->carry = 0);
  place += GET_SIZE;
  type = get_type(op_code, 1);
  two = get_res_for_type(mem, proc, place, &type);
  if (type == -1)
    return (proc->carry = 0);
  place += GET_SIZE;
  place = mem->box[place % MEM_SIZE] - 1;
  if (place < 0 || place > REG_NUMBER)
    return (proc->carry = 0);
  proc->reg[place] = one ^ two;
  proc->carry = 1;
  return (0);
}
