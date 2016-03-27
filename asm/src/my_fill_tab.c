/*
** my_fill_tab.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Mar 18 14:13:32 2016 vincent mesquita
** Last update Sat Mar 26 22:02:48 2016 vincent mesquita
*/

#include <stdlib.h>

int		my_fill_tab(char tab[], int size, char *str)
{
  int		i;

  if (tab == NULL || str == NULL)
    return (-1);
  i = 0;
  while (str[i] && i < size)
    {
      tab[i] = str[i];
      i += 1;
    }
  while (i <= size + 3)
    tab[i++] = 0;
  return (0);
}
