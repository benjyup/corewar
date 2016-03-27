/*
** pars_label.c for pars_label.c in /home/vincen_s/rendu/CPE_2015_corewar/asm
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Fri Mar 25 14:52:18 2016 Vincent Florian
** Last update Sun Mar 27 20:05:50 2016 Vincent Florian
*/

#include <stdlib.h>
#include "asm.h"

int		my_find_after(t_first *first, t_int *l_int, t_label *current)
{
  int		a_pos;
  int		l_pos;
  char		*label;
  t_label	*curr;

  label = current->label;
  a_pos = current->position;
  curr = current->next;
  l_pos = -1;
  while (curr != NULL && curr != first->root)
    {
      if (my_strcomp_label(&label[2], curr->label) == 1)
	{
	  l_pos = curr->position;
	  my_add_to_end_int_list(l_int, l_pos - a_pos);
	  return (0);
	}
      curr = curr->next;
    }
  return (-1);
}

int		my_find_before(t_first *first, t_int *l_int, t_label *current)
{
  int		a_pos;
  int		l_pos;
  char		*label;
  t_label	*curr;

  label = current->label;
  a_pos = current->position;
  curr = current->prev;
  l_pos = -1;
  while (curr != NULL && curr != first->root)
    {
      if (my_strcomp_label(&label[2], curr->label) == 1)
	{
	  l_pos = curr->position;
	  my_add_to_end_int_list(l_int, (l_pos - a_pos));
	  return (0);
	}
      curr = curr->prev;
    }
  return (-1);
}

int		my_add_label_tolist(t_int *l_int, t_first *first)
{
  t_label	*current;

  current = first->root->next;
  while (current != NULL && current != first->root)
    {
      if (current->label[0] == '%')
	{
	  if ((my_find_after(first, l_int, current) == -1) &&
	      (my_find_before(first, l_int, current) == -1))
	    {
	      my_put_error2("asm", current->line + 1, first->filename,
			    "Undefined Label\n");
	      return (-1);
	    }
	}
      current = current->next;
    }
  return (1);
}

int		check_double_label(t_first *first)
{
  t_label	*current;
  t_label	*curr2;
  char		*label;

  current = first->root->next;
  while (current != first->root)
    {
      label = current->label;
      if (label[0] != '%' && label[1] != ':')
	{
	  curr2 = current->next;
	  while (curr2 != NULL && curr2 != first->root)
	    {
	      if (my_strcomp(curr2->label, label))
		{
		  my_put_error2("asm", curr2->line, first->filename,
				"label already declared\n");
		  return (-1);
		}
	      curr2 = curr2->next;
	    }
	}
      current = current->next;
    }
  return (1);
}

t_int		*pars_first(t_first *first)
{
  t_label	*current;
  t_int		*l_int;

  if ((l_int = my_init_int_list()) == NULL)
    return (NULL);
  current = first->root->next;
  while (current != first->root)
    {
      if (my_check_label(current, first, -1) == -1 || current->position < 0)
	return (NULL);
      current = current->next;
    }
  if ((check_double_label(first)) == -1 ||
      (my_add_label_tolist(l_int, first)) == -1)
    return (NULL);
  return (l_int);
}
