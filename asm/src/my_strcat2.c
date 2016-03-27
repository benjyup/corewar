/*
** my_strcat2.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Mar 18 13:40:13 2016 vincent mesquita
** Last update Fri Mar 18 13:41:18 2016 vincent mesquita
*/

#include <stdlib.h>

char		*my_strcat2(char *dest, char *src)
{
  char		*str;
  int		i;
  int		h;

  i = 0;
  h = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (dest != NULL && dest[i] && dest[i] != '.')
    i = i + 1;
  while (src != NULL && src[h])
    h = h + 1;
  if ((str = malloc((i + h + 1))) == NULL)
    return (NULL);
  i = 0;
  while (dest != NULL && dest[i] && dest[i] != '.')
    {
      str[i] = dest[i];
      i += 1;
    }
  h = 0;
  while (src[h])
    str[i++] = src[h++];
  str[i] = '\0';
  return (str);
}
