/*
** my_line_is_empty.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sat Mar 26 16:47:24 2016 vincent mesquita
** Last update Sat Mar 26 21:59:40 2016 Vincent Florian
*/

int		my_line_is_not_empty(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (1);
      i += 1;
    }
  return (0);
}
