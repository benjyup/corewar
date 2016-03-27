/*
** init.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Mar 16 11:58:02 2016 Timothée Puentes
** Last update Sat Mar 26 15:43:17 2016 Peixoto Benjamin
*/

#include <stdlib.h>
#include "my_basics.h"
#include "op.h"
#include "asm.h"

int		add_champ(t_mem *mem, char *name, int nb, int champ)
{
  int		c;

  c = 0;
  while (c < champ)
    {
      if (mem->champ[champ].number == mem->champ[c].number)
	return (-1 * error_int("Already a Champ owning this number\n"));
      c += 1;
    }
  if (mem->champ[champ].number == -1)
    mem->champ[champ].number = nb;
  mem->champ[champ].live = 0;
  if ((mem->champ[champ].name = my_strcpy(name)) == NULL ||
      (mem->champ[champ].tmp = my_strcpy("")) == NULL)
    return (-1);
  mem->champ[champ].size_ins = 0;
  if (mem->a_opt == -1)
    mem->champ[champ].offset = -1;
  return (champ);
}

int		add_process(t_mem *mem, int nb, int act)
{
  int		i;
  int		c;
  t_process	*new;

  if ((new = malloc(sizeof(t_process) * (mem->nb_proc + 2))) == NULL)
    return (error_int("Malloc failed\n"));
  c = 0;
  while (c < mem->nb_proc)
    {
      new[c] = mem->proc[c];
      c += 1;
    }
  i = -1;
  while ((i += 1) < REG_NUMBER)
    new[c].reg[i] = ((i == 0) ? (nb) : (0));
  new[c].cycle = 0;
  new[c].carry = 1;
  new[c].act = act;
  new[c].instruc = NULL;
  free(mem->proc);
  mem->proc = new;
  mem->nb_proc += 1;
  return (0);
}

t_mem		*init_memory()
{
  int		c;
  t_mem		*mem;

  if ((mem = malloc(sizeof(t_mem))) == NULL ||
      (mem->proc = malloc(sizeof(t_process))) == NULL)
    return (error_pnt("Malloc failed\n"));
  mem->proc[0].act = -1;
  c = 0;
  while (c++ < MEM_SIZE)
    mem->box[c] = 0;
  c = 0;
  while (c < MAX_CHAMP)
    {
      mem->champ[c].number = -1;
      mem->champ[c].name = NULL;
      c += 1;
    }
  mem->n_opt = -1;
  mem->a_opt = -1;
  mem->nb_proc = 0;
  mem->nb_live = 0;
  mem->last_alive = -1;
  mem->cycle_to_dumping = -1;
  return (mem);
}

void		free_memory(t_mem *mem)
{
  int		c;

  c = 0;
  while (c < MAX_CHAMP)
    {
      if (mem->champ[c].name == NULL)
	free(mem->champ[c].name);
      c += 1;
    }
  free(mem->proc);
  free(mem);
}
