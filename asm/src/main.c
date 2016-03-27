/*
** main.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Mar 17 16:22:49 2016 vincent mesquita
** Last update Mon Mar 21 17:51:45 2016 Vincent Florian
*/

#include <stdlib.h>
#include "asm.h"

static int	my_usage(int ac, char **av, char **ae)
{
  if (ae == NULL || ae[0] == NULL)
    {
      my_puterror("Error: Environment is not set\n");
      return (0);
    }
  if (ac == 1)
    {
      my_puterror("Usage : ");
      my_puterror(av[0]);
      my_puterror("file_name[.s] ....\n");
      return (0);
    }
  return (1);
}

int		main(int ac, char **av, char **ae)
{
  int		i;

  if (!my_usage(ac, av, ae))
    return (0);
  i = 0;
  while (av[++i] != NULL)
    my_asm(av[i]);
  return (0);
}
