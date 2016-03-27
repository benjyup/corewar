/*
** comment.c for  in /home/mesqui_v/test
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Mar 25 11:57:34 2016 vincent mesquita
** Last update Sat Mar 26 14:39:22 2016 Vincent Florian
*/

#include <stdlib.h>
#include "asm.h"

int			mine_is_a_comment(char *str)
{
  if (str == NULL)
    return (0);
  if (str[0] == COMMENT_CHAR)
    return (1);
  return (0);
}
