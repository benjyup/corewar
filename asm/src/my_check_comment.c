/*
** my_check_comment.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Tue Mar 22 15:10:44 2016 vincent mesquita
** Last update Sat Mar 26 22:06:25 2016 vincent mesquita
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"

int		my_check_comment(char **wordtab,
				 t_header *header,
				 t_file_info *fi)
{
  if (wordtab[0] == NULL || wordtab[1] == NULL
      || my_strcomp(wordtab[0], COMMENT_CMD_STRING) != 1
      || fi->name_put == 0 || fi->comment_put == 1 || fi->code_put == 1)
    {
      if (fi->comment_put == 1)
	my_put_error("Asm",
		     fi, "Your file must have only one comment.\n");
      else if (wordtab[1] == NULL)
	my_put_error("Asm", fi, "invalid comment.\n");
      else
	my_put_error("Asm",
		     fi, "Your comment must be next to the name.\n");
      return (-1);
    }
  if (my_strlen(wordtab[1]) > COMMENT_LENGTH)
    my_put_warning("Asm", fi, ERROR2);
  if (my_fill_tab(header->comment, COMMENT_LENGTH, wordtab[1]) == -1)
    return (-1);
  fi->comment_put = 1;
  if (write(fi->fd, header, sizeof(*header)) != sizeof(*header))
    return (-1);
  return (0);
}
