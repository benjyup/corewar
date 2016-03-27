/*
** my_list_fonction.c for my_list_fonction.c in /home/vincen_s/rendu/CPE_2015_corewar/asm/src
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Tue Mar 22 18:04:53 2016 Vincent Florian
** Last update Sat Mar 26 21:55:55 2016 vincent mesquita
*/

#include <stdlib.h>
#include "asm.h"

int		my_add_to_end_label_list(t_label *root, char *label,
					 int pos, int line)
{
  t_label	*current;
  t_label	*new_flag;

  if (root == NULL || label == NULL)
    return (-1);
  current = root->prev;
  if ((new_flag = malloc(sizeof(*new_flag))) == NULL)
    return (-1);
  if ((new_flag->label = my_strcpy(label)) == NULL)
    return (-1);
  new_flag->next = root;
  new_flag->prev = current;
  new_flag->position = pos;
  new_flag->line = line;
  root->prev = new_flag;
  current->next = new_flag;
  return (0);
}

void		my_delete_to_begin_int_list(t_int *root)
{
  t_int		*current;
  t_int		*to_free;

  if (root->next == root)
    return ;
  to_free = root->next;
  current = root->next->next;
  if (to_free != NULL)
    free(to_free);
  root->next = current;
  current->prev = root;
}

int		my_add_to_end_int_list(t_int *root, int position)
{
  t_int		*current;
  t_int		*new_flag;

  if (root == NULL)
    return (-1);
  current = root->prev;
  if ((new_flag = malloc(sizeof(*new_flag))) == NULL)
    return (-1);
  new_flag->next = root;
  new_flag->prev = current;
  new_flag->pos = position;
  root->prev = new_flag;
  current->next = new_flag;
  return (0);
}
