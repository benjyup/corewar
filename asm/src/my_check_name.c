/*
** my_check_name.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Tue Mar 22 15:07:56 2016 vincent mesquita
** Last update Sat Mar 26 15:18:23 2016 Vincent Florian
*/

#include <stdlib.h>
#include "asm.h"

int		my_check_name(char **wordtab,
			      t_header *header,
			      t_file_info *fi)
{
  if (wordtab[0] == NULL || wordtab[1] == NULL
      || my_strcomp(wordtab[0], NAME_CMD_STRING) != 1
      || fi->name_put == 1 || fi->comment_put == 1 || fi->code_put == 1)
    {
      if (fi->name_put == 1)
	my_put_error("Asm", fi, "Your file must have only one name.\n");
      else if (wordtab[1] == NULL)
	my_put_error("Asm",
		     fi, "invalid name.\n");
      else
	my_put_error("Asm",
		     fi, "Your file must begin with a valid name.\n");
      return (-1);
    }
  if (my_strlen(wordtab[1]) > PROG_NAME_LENGTH)
    my_put_warning("Asm", fi, ERROR1);
  header->magic = my_endian(COREWAR_EXEC_MAGIC);
  if (my_fill_tab(header->prog_name,
		  PROG_NAME_LENGTH, wordtab[1]) == -1)
    return (-1);
  fi->name_put = 1;
  return (0);
}
