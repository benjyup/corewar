/*
** main.c for main.c in /home/vincen_s/rendu/BOOTSTRAP_COREWAR
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Mon Mar 14 14:07:13 2016 Vincent Florian
** Last update Mon Mar 14 17:47:48 2016 vincent mesquita
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;
  int	neg;

  i = 0;
  nbr = 0;
  neg = 0;
  if (str == NULL)
    return (-1);
  while ((str[i] < '0' || str[i] > '9') && str[i] != 0)
    {
      if (str[i] == '-')
	neg = neg + 1;
      i = i + 1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10 + str[i] - 48;
      i = i + 1;
    }
  if (neg % 2 == 1)
    nbr = nbr * (-1);
  return (nbr);
}

char		*my_strcat2(char *dest, char *src)
{
  char		*str;
  int		i;
  int		h;

  i = 0;
  h = 0;
  while (dest != NULL && dest[i] && dest[i] != '.')
    i = i + 1;
  while (src != NULL && src[h])
    h = h + 1;
  if ((str = malloc((i + h + 1))) == NULL)
    return (NULL);
  i = 0;
  while (dest != NULL && dest[i] && dest[i] != '.')
    str[i] = dest[i++];
  h = 0;
  while (src[h])
    str[i++] = src[h++];
  str[i] = '\0';
  return (str);
}

int		my_strcomp(char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s1[i])
    i++;
  while (s2[j])
    j++;
  if (i != j)
    return (-1);
  i = 0;
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (-1);
      i++;
    }
  return (0);
}

void		my_asm(char *str, int fd2)
{
  int	i;
  int	j;
  char	*ptr;
  int	h;
  int	total;

  h = 0x01;
  j = 0;
  i = 0;
  while (str[i] && str[i] != ' ')
    ptr[j++] = str[i++];
  ptr[j] = 0;
  i++;
  j = 0;
  if (my_strcomp("add", ptr) == 0)
    write(fd2, &h, 1);
  while (str[i] && str[i] != ' ')
    ptr[j++] = str[i++];
  ptr[j] = 0;
  j = 0;
  i++;
  h = my_getnbr(ptr);
  total = h;
  write(fd2, &h, 4);
  while (str[i] && str[i] != ' ')
    ptr[j++] = str[i++];
  ptr[j] = 0;
  h = my_getnbr(ptr);
  total += h;
  write(fd2, &h, 4);
  /* printf("%d %d\n", total, sizeof(h)); */
  write(fd2, "\n", 1);
  /* write(fd2, &total, 4); */
}

int		main(int ac, char **av)
{
  int		fd;
  char		*str;
  int		fd2;

  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (0);
  my_putchar('a');
  if ((fd2 = open(my_strcat2(av[1], ".bytecode"), O_CREAT | O_RDWR)) == -1)
    return (0);
  str = get_next_line(fd);
  my_asm(str, fd2);
  str = get_next_line(fd);
  my_asm(str, fd2);
  return (0);
}
