/*
** my_asm.c<2> for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Mar 17 16:23:06 2016 vincent mesquita
** Last update Sun Mar 27 20:26:07 2016 Vincent Florian
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "asm.h"

t_instruction_fptr	fptr_tab[INSTRUCTION_NBR] =
  {
    {".name", &my_check_name},
    {".comment", &my_check_comment},
    {"live", &my_check_live},
    {"ld", &my_check_ld},
    {"st", &my_check_st},
    {"add", &my_check_add},
    {"sub", &my_check_sub},
    {"and", &my_check_and},
    {"or", &my_check_or},
    {"xor", &my_check_xor},
    {"zjmp", &my_check_zjmp},
    {"ldi", &my_check_ldi},
    {"sti", &my_check_sti},
    {"fork", &my_check_fork},
    {"lld", &my_check_lld},
    {"lldi", &my_check_lldi},
    {"lfork", &my_check_lfork},
    {"aff", &my_check_aff}
  };

static int	my_check_line(char *line,
			      t_header *header,
			      t_file_info *fi)
{
  char		**wordtab;
  int		i;

  if (line == NULL || (wordtab = my_str_to_wordtab(line, ' ')) == NULL)
    return (-1);
  if ((wordtab = my_delete_label(wordtab)) == NULL)
    return (-1);
  i = 0;
  while (i < INSTRUCTION_NBR)
    {
      if (my_strcomp(wordtab[0], fptr_tab[i].name) == 1)
	{
	  if (fptr_tab[i].fptr(wordtab, header, fi) == -1)
	    return (-1);
	  i = INSTRUCTION_NBR;
	}
      i += 1;
    }
  if (i == INSTRUCTION_NBR)
    my_put_error("Asm", fi, "Unknow instruction.\n");
  my_free_wordtab(wordtab);
  return (0);
}

static int	my_fill_header_and_op(t_header *header,
				      int fd,
				      t_file_info *fi,
				      t_first *first)
{
  char		*line;

  header->prog_size = my_endian(first->ps);
  fi->line_nbr = 1;
  while ((line = get_next_line(fd)) != NULL)
    {
      if (line[0] != 0 && my_line_is_not_empty(line))
	if (my_epure_str(line) == -1)
	  return (-1);
      if (line[0] != 0 && my_line_is_not_empty(line))
	if (my_check_line(line, header, fi) == -1)
	  return (-1);
      fi->line_nbr += 1;
      free(line);
    }
  return (0);
}

int		my_asm(char *filename)
{
  char		*new_name;
  t_header	header;
  t_file_info	fi;
  int		fd;
  t_first	*first;

  fi.name_put = 0;
  fi.comment_put = 0;
  fi.code_put = 0;
  if ((first = my_ps(filename, 2)) == NULL)
    return (-1);
  fi.label = pars_first(first);
  if ((fi.filename = filename) == NULL
      || (fd = open(filename, O_RDONLY)) == -1
      || (new_name = my_strcat2(filename, ".cor")) == NULL
      || (fi.fd = open(new_name, O_WRONLY | O_CREAT | O_TRUNC,
		       S_IRUSR | S_IRGRP | S_IRGRP | S_IWGRP
		       | S_IWUSR | S_IROTH)) == -1
      || my_fill_header_and_op(&header, fd, &fi, first) == -1)
    return (-1);
  close(fd);
  close(fi.fd);
  free(new_name);
  return (0);
}
