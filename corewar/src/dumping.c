/*
** dumping.c for  in /home/puente_t/rendu/CPE/CPE_2015_corewar/corewar
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Mar 24 10:37:58 2016 Timothée Puentes
** Last update Thu Mar 24 11:49:26 2016 Peixoto Benjamin
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "asm.h"
#include "my_basics.h"

int		print_hexa(int fd, unsigned char octet, char *base)
{
  unsigned char	fir;
  unsigned char	sec;

  fir = octet / 16;
  sec = octet % 16;
  if (write(fd, &base[(unsigned int)fir], 1) == -1 ||
      write(fd, &base[(unsigned int)sec], 1) == -1)
    return (1);
  return (0);
}

int		dumping(t_mem *mem)
{
  int		fd;
  int		c;

  if ((fd = open("memory_dump", O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IRGRP | S_IRGRP | S_IWGRP
		 | S_IWUSR | S_IROTH)) == -1)
    return (1);
  c = 0;
  while (c < MEM_SIZE)
    {
      if (c % 32 == 0 && c != 0)
	if (write(fd, "\n", 1) == -1)
	  return (1);
      if (print_hexa(fd, mem->box[c], "0123456789ABCDEF"))
	return (1);
      c += 1;
    }
  close(fd);
  return (0);
}
