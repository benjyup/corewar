/*
** main.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Mar 14 12:39:22 2016 vincent mesquita
** Last update Sat Mar 26 15:57:45 2016 Peixoto Benjamin
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include "my_basics.h"

char		*my_strcat_vm(char *str1, char *str2, int size1, int size2)
{
  char		*cpy;
  int		i;
  int		h;

  if ((cpy = malloc((size1 + size2 + 1) * sizeof(char))) == NULL ||
      str2 == NULL)
    return (error_pnt("Malloc failed\n"));
  i = 0;
  while (i < size1)
    {
      cpy[i] = str1[i];
      i = i + 1;
    }
  h = 0;
  while (h < size2)
    cpy[i++] = str2[h++];
  if (str1 != NULL)
    free(str1);
  cpy[i] = '\0';
  return (cpy);
}

int		read_files2(t_mem *mem, char *buffer, int fd, int rank)
{
  int		ret;

  ret = 1;
  while (ret > 0)
    {
      if ((ret = read(fd, buffer, 2048)) == -1)
	return (1);
      buffer[ret] = 0;
      if ((mem->champ[rank].tmp =
	   my_strcat_vm(mem->champ[rank].tmp, buffer,
			mem->champ[rank].size_ins, ret)) == NULL)
	return (1);
      mem->champ[rank].size_ins += ret;
    }
}

int		read_files(const char *name, t_mem *mem,
			   int nb, int nb_champ)
{
  t_header	header;
  int		fd;
  char		buffer[2048 + 1];
  int		rank;
  t_file_info	filename;

  filename.filename = NULL;
  filename.line_nbr = 0;
  if ((fd = open(name, O_RDONLY)) == -1)
    {
      my_putstr("VM: No such file\n");
      my_put_error("VM", &filename, "No such file\n");
      return (1);
    }
  if (read(fd, &header, sizeof(t_header)) != sizeof(t_header) ||
      (rank = add_champ(mem, header.prog_name, nb_champ, nb)) == -1)
    return (1);
  if (read_files2(mem, buffer, fd, rank) == 1)
    return (1);
  close(fd);
  return (0);
}

int		prepare_my_champ(int ac, char **av, t_mem *mem)
{
  int		c;
  int		nb_champ;
  int		nb;

  nb = 0;
  nb_champ = 0;
  c = 1;
  while (c < ac)
    {
      if (option(c, av, mem, nb) == -1)
	{
	  if (mem->n_opt != 1)
	    nb_champ = nb_champ + 1;
	  if (read_files(av[c], mem, nb, nb_champ))
	    return (1);
	  nb += 1;
	  mem->n_opt = -1;
	  mem->a_opt = -1;
	}
      else
	c += 1;
      c += 1;
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_mem		*mem;

  if (ac == 1)
    print_help(av[0]);
  if ((mem = init_memory()) == NULL)
    return (1);
  if (prepare_my_champ(ac, av, mem) == 1)
    return (1);
  if (choose_place(mem))
    return (error_int("No Champion to use\n"));
  else if (core(mem))
    return (error_int("Malloc failed\n"));
  free_memory(mem);
  return (0);
}
