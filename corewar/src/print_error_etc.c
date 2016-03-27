/*
** print_error_etc.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar/corewar
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Mar 24 10:33:07 2016 Timothée Puentes
** Last update Fri Mar 25 16:24:39 2016 Timothée Puentes
*/

#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"
#include "my_basics.h"

void		print_live_victory(t_mem *mem,
				   int win_or_live,
				   int nb)
{
  int		c;

  c = 0;
  while (c < MAX_CHAMP)
    {
      if (mem->champ[c].number == nb)
	break;
      c += 1;
    }
  if (c == MAX_CHAMP)
    return ;
  my_putstr("Le joueur ");
  my_put_nbr(nb);
  my_putstr("(");
  my_putstr(mem->champ[c].name);
  my_putstr(((win_or_live) ? (") a gagné.\n") : (") est en vie.\n")));
}

void		my_vm_put_error(char *who,
				char *error)
{
  if (who == NULL || error == NULL)
    return ;
  my_puterror(who);
  my_puterror(": ");
  my_puterror("\033[1;31m");
  my_puterror("Error");
  my_puterror("\033[0m");
  my_puterror(" -> ");
  my_puterror("\033[1;36m");
  my_puterror(error);
  my_puterror("\033[0m");
}

void		*error_pnt(char *str)
{
  my_vm_put_error("VM", str);
  return (NULL);
}

int		error_int(char *str)
{
  my_vm_put_error("VM", str);
  return (1);
}

int		print_help(char *str)
{
  my_putstr(str);
  my_putstr(" [-dump nbr_cycle] [[-n prog_number]");
  my_putstr(" [-a load_address ] prog_name] ...\n");
  exit(0);
}
