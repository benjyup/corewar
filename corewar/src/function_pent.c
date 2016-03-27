/*
** function_pent.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar/corewar
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Tue Mar 22 17:07:44 2016 Timothée Puentes
** Last update Fri Mar 25 16:57:58 2016 Timothée Puentes
*/

#include "corewar.h"
#include "my_basics.h"

int		get_res_for_di(t_mem *mem, t_process *proc, int place, int *type)
{
  int		res;

  res = 0;
  if (*type == T_DIR || *type == T_IND)
    res = (short)read_n_char_at_x(mem, IND_SIZE, place);
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

int		ldi(t_mem *mem, t_process *proc)
{
  int		op_code;
  int		type;
  int		place;
  int		somme;

  op_code = mem->box[(proc->act + 1) % MEM_SIZE];
  type = get_type(op_code, 0);
  place = proc->act + 2;
  somme = get_res_for_di(mem, proc, place, &type);
  if (type == -1)
    return (proc->carry = 0);
  place += GET_SIZE;
  type = get_type(op_code, 1);
  somme += get_res_for_di(mem, proc, place, &type);
  if (type == -1)
    return (proc->carry = 0);
  place += GET_SIZE;
  op_code = place;
  place = mem->box[place % MEM_SIZE] - 1;
  if (place < 0 || place > REG_NUMBER)
      return (proc->carry = 0);
  proc->reg[place] =
    read_n_char_at_x(mem, 4, get_real_pos(proc->act + (somme % IDX_MOD)));
  proc->carry = 1;
  return (0);
}

int		lldi(t_mem *mem, t_process *proc)
{
  int		op_code;
  int		type;
  int		place;
  int		somme;

  op_code = mem->box[(proc->act + 1) % MEM_SIZE];
  type = get_type(op_code, 0);
  place = proc->act + 2;
  somme = get_res_for_di(mem, proc, place, &type);
  if (type == -1)
    return (proc->carry = 0);
  place += GET_SIZE;
  type = get_type(op_code, 1);
  somme += get_res_for_di(mem, proc, place, &type);
  if (type == -1)
    return (proc->carry = 0);
  place += GET_SIZE;
  place = mem->box[place % MEM_SIZE] - 1;
  if (place < 0 || place > REG_NUMBER)
      return (proc->carry = 0);
  proc->reg[place] =
    read_n_char_at_x(mem, 4, get_real_pos(proc->act + somme));
  proc->carry = 1;
  return (0);
}

int		sti(t_mem *mem, t_process *proc)
{
  int		op_code;
  int		reg;
  int		rank;
  int		place;
  int		type;

  op_code = mem->box[(proc->act + 1) % MEM_SIZE];
  reg = mem->box[(proc->act + 2) % MEM_SIZE] - 1;
  if (reg < 0 || reg > REG_NUMBER)
    return (0);
  reg = proc->reg[reg];
  place = get_real_pos(proc->act + 3);
  type = ((get_type(op_code, 1) == T_REG) ? (T_REG) : (T_IND));
  rank = get_res_for_di(mem, proc, place, &type);
  place += GET_SIZE;
  type = ((get_type(op_code, 1) == T_REG) ? (T_REG) : (T_IND));
  rank += get_res_for_di(mem, proc, place, &type);
  store_n_char_at_x(mem, reg, DIR_SIZE, proc->act + rank);
  return (0);
}
