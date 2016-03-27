/*
** my_writes.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Tue Mar 22 16:04:06 2016 vincent mesquita
** Last update Sat Mar 26 21:40:06 2016 Vincent Florian
*/

#include <unistd.h>
#include "asm.h"

t_write_fptr	write_tab[WRITE_NBR] =
  {
    {REGISTRE, &my_write_register},
    {DIRECT, &my_write_direct},
    {INDIRECT, &my_write_indirect}
  };

int		my_write(int fd, const void *buff, int count)
{
  if (write(fd, buff, count) != count)
    {
      my_puterror("Asm: Error: Write() failed.\n");
      return (-1);
    }
  return (count);
}

int		my_write_register(char *str, t_file_info *fi)
{
  int		nbr;

  if ((nbr = my_get_reg(str, fi)) == -1
      || my_write(fi->fd, &nbr, REG_SIZE) != REG_SIZE)
    return (-1);
  return (0);
}

int		my_write_indirect(char *str, t_file_info *fi)
{
  int		nbr;

  nbr = my_get_ind(str, fi);
  if (my_write(fi->fd, &nbr, IND_SIZE) != IND_SIZE)
    return (-1);
  return (0);
}

int		my_write_direct(char *str, t_file_info *fi)
{
  int		nbr;

  nbr = my_get_dir(str, fi, 0);
  if (my_write(fi->fd, &nbr, DIR_SIZE) != DIR_SIZE)
    return (-1);
  return (0);
}

int		my_cor_write(char **wordtab,
			     unsigned char args[MAX_ARGS_NUMBER],
			     t_file_info *fi)
{
  int		i;
  int		j;

  i = 0;
  while (wordtab[i] != NULL)
    {
      j = -1;
      while (++j < WRITE_NBR)
	if (args[i] == write_tab[j].flag)
	  if (write_tab[j].fptr(wordtab[i], fi) == -1)
	    return (-1);
      i += 1;
    }
  return (0);
}
