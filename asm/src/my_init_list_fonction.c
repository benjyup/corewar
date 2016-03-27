/*
** my_init_list_fonction.c for  in /home/vincen_s/rendu/CPE_2015_corewar/asm
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Sat Mar 26 19:47:15 2016 Vincent Florian
** Last update Sat Mar 26 19:48:12 2016 Vincent Florian
*/

#include <stdlib.h>
#include "asm.h"

t_int		*my_init_int_list(void)
{
  t_int		*root;

  if ((root = malloc(sizeof(*root))) == NULL)
    return (NULL);
  root->next = root;
  root->prev = root;
  root->pos = 0;
  return (root);
}

t_label		*my_init_label_list(void)
{
  t_label	*root;

  if ((root = malloc(sizeof(*root))) == NULL)
    return (NULL);
  root->next = root;
  root->prev = root;
  root->label = NULL;
  root->position = 0;
  return (root);
}

t_first		*my_init_first_list(void)
{
  t_first	*root;

  if ((root = malloc(sizeof(*root))) == NULL)
    return (NULL);
  root->ps = 0;
  root->root = NULL;
  return (root);
}
