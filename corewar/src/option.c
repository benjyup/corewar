/*
** option.c for option in /home/peixot_b/Depot/CPE/CPE_2015_corewar/corewar/src
** 
** Made by Peixoto Benjamin
** Login   <peixot_b@epitech.net>
** 
** Started on  Thu Mar 24 11:20:52 2016 Peixoto Benjamin
** Last update Sun Mar 27 18:07:56 2016 Peixoto Benjamin
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "corewar.h"
#include "my_basics.h"

int		my_dump_opt(t_mem *mem, char *str, char **av)
{
  int		new_nb_dump;
  int		i;

  if (str == NULL)
    print_help(av[0]);
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	print_help(av[0]);
      i = i + 1;
    }
  if ((new_nb_dump = my_getnbr(str)) == -1)
    print_help(av[0]);
  if (new_nb_dump >= 0 && new_nb_dump < 2147483647)
    mem->cycle_to_dumping = new_nb_dump;
  else
    print_help(av[0]);
  return (0);
}

int		my_n_opt(t_mem *mem, char *str, char **av, int nb_champ)
{
  int		new_nb_champ;
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	print_help(av[0]);
      i = i + 1;
    }
  if ((new_nb_champ = my_getnbr(str)) == -1)
    print_help(av[0]);
  if (new_nb_champ > 0 && new_nb_champ <= 4)
    mem->champ[nb_champ].number = new_nb_champ;
  else
    print_help(av[0]);
  mem->n_opt = 1;
  return (0);
}

int		my_a_opt(t_mem *mem, char *str, char **av, int nb_champ)
{
  int		new_nb_champ;
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	print_help(av[0]);
      i = i + 1;
    }
  if ((new_nb_champ = my_getnbr(str)) == -1)
    print_help(av[0]);
  if (new_nb_champ >= 0 && new_nb_champ <= MEM_SIZE)
    mem->champ[nb_champ].offset = new_nb_champ;
  else
    print_help(av[0]);
  mem->a_opt = 1;
  return (0);
}

int		option(int arg, char **av, t_mem *mem, int nb_champ)
{
  if (av[arg][0] != '-')
    return (-1);
  if (my_strcomp("-dump", av[arg]) == 1)
    {
      my_dump_opt(mem, av[arg + 1], av);
      return (1);
    }
  else if (my_strcomp("-n", av[arg]) == 1)
    {
      my_n_opt(mem, av[arg + 1], av, nb_champ);
      return (1);
    }
  else if (my_strcomp("-a", av[arg]) == 1)
    {
      my_a_opt(mem, av[arg + 1], av, nb_champ);
      return (1);
    }
  else
    print_help(av[0]);
  return (0);
}
