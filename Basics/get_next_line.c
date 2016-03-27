/*
** get_next_line.c for get_next_line in /home/peixot_b/Depot/CPE/CPE_2015_getnextline
**
** Made by Peixoto Benjamin
** Login   <peixot_b@epitech.net>
**
** Started on  Thu Mar  3 15:14:03 2016 Peixoto Benjamin
** Last update Wed Mar 16 16:16:31 2016 vincent mesquita
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static int	my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

static char	*my_strncpy(char *dest, char *src, int n)
{
  int		c;

  c = -1;
  while (src[++c] && c < n)
    dest[c] = src[c];
  if (c == 0 || n == 0)
    dest[c] = 0;
  return (dest);
}

static char	*my_new_line(char *line, int i, char *buff, int *begin)
{
  char		*str;
  int		old_lenght;

  old_lenght = (line) ? my_strlen(line) : 0;
  if ((str = malloc((old_lenght + i + 1) * sizeof(*str))) == NULL)
    return (NULL);
  my_strncpy(str, line ? line : "", old_lenght);
  my_strncpy(str + old_lenght, buff + *begin, i);
  str[old_lenght + i] = 0;
  *begin += i + 1;
  return (str);
}

char		*get_next_line(const int fd)
{
  int		i;
  char		*line;
  static int	begin;
  static char	buff[READ_SIZE + 1];
  static int	buf_base = 0;

  i = 0;
  line = 0;
  while (1)
    {
      if (begin >= buf_base)
	{
	  begin = 0;
	  if (!(buf_base = read(fd, buff, READ_SIZE)))
	    return (line);
	  i = 0;
	}
      if (buff[begin + i] == '\n')
	return (line = my_new_line(line, i, buff, &begin));
      if (begin + i == buf_base - 1)
	line = my_new_line(line, i + 1, buff, &begin);
      ++i;
    }
}
