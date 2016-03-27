/*
** vincent.h for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/include
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Mar 14 12:46:01 2016 vincent mesquita
** Last update Sat Mar 26 22:06:33 2016 vincent mesquita
*/

#ifndef VINCENT_H_
# define VINCENT_H_

# define REGISTRE		1
# define DIRECT			2
# define INDIRECT		3
# define INSTRUCTION_NBR	18
# define WRITE_NBR		3
# define ERROR1 "The program's name is to long. It will be truncated.\n"
# define ERROR2 "The program's comment is to long. It will be truncated.\n"

typedef struct	s_file_info
{
  char		*filename;
  int		fd;
  int		line_nbr;
  int		name_put;
  int		comment_put;
  int		code_put;
  t_int		*label;
}		t_file_info;

typedef struct	s_instruction_fptr
{
  char		*name;
  int		(*fptr)(char **wordtab,
			t_header *header,
			t_file_info *fi);
}		t_instruction_fptr;

typedef struct	s_write_fptr
{
  unsigned char	flag;
  int		(*fptr)(char *str,
			t_file_info *fi);
}		t_write_fptr;

extern t_write_fptr	write_tab[WRITE_NBR];

typedef union		s_endian_short
{
  unsigned char		c[2];
  short			nb;
}			t_endian_short;

char		**my_delete_label(char **wordtab);
int		mine_is_a_label(char *str);
int		my_write_index(unsigned char arg,
			       char *str,
			       t_file_info *fi);
int		my_cor_write(char **wordtab,
			     unsigned char args[MAX_ARGS_NUMBER],
			     t_file_info *fi);
int		my_endian(int	nbr);
int		my_endian_short(short nbr);
int		my_get_reg(char *str, t_file_info *fi);
int		my_get_ind(char *str, t_file_info *fi);
int		my_get_dir(char *str, t_file_info *fi, int flag);
int		my_write(int fd, const void *buff, int count);
int		my_write_register(char *str, t_file_info *fi);
int		my_write_direct(char *str, t_file_info *fi);
int		my_write_indirect(char *str, t_file_info *fi);
int		my_args_are_valid(char **wordtab,
				  t_op *op,
				  t_file_info *fi);
void		my_put_error(char *who,
			     t_file_info *fi,
			     char *error);
void		my_put_warning(char *who,
			       t_file_info *fi,
			       char *error);
int		my_asm(char *filename);
int		my_strcomp_asm(char *str);
void		my_epure_tabulation(char *str);
char		*my_strcat2(char *dest, char *src);
int		my_fill_tab(char tab[], int size, char *str);
int		my_check_live(char **wordtab,
			      t_header *header,
			      t_file_info *fi);
int		my_check_name(char **wordtab,
			      t_header *header,
			      t_file_info *fi);
int		my_check_comment(char **wordtab,
				 t_header *header,
				 t_file_info *fi);
int		my_check_ld(char **wordtab,
			    t_header *header,
			    t_file_info *fi);
int		my_check_st(char **wordtab,
			    t_header *header,
			    t_file_info *fi);
int		my_check_add(char **wordtab,
			     t_header *header,
			     t_file_info *fi);
int		my_check_sub(char **wordtab,
			     t_header *header,
			     t_file_info *fi);
int		my_check_and(char **wordtab,
			     t_header *header,
			     t_file_info *fi);
int		my_check_or(char **wordtab,
			    t_header *header,
			    t_file_info *fi);
int		my_check_xor(char **wordtab,
			     t_header *header,
			     t_file_info *fi);
int		my_check_zjmp(char **wordtab,
			      t_header *header,
			      t_file_info *fi);
int		my_check_ldi(char **wordtab,
			     t_header *header,
			     t_file_info *fi);
int		my_check_sti(char **wordtab,
			     t_header *header,
			     t_file_info *fi);
int		my_check_fork(char **wordtab,
			      t_header *header,
			      t_file_info *fi);
int		my_check_lld(char **wordtab,
			     t_header *header,
			     t_file_info *fi);
int		my_check_lldi(char **wordtab,
			      t_header *header,
			      t_file_info *fi);
int		my_check_lfork(char **wordtab,
			       t_header *header,
			       t_file_info *fi);
int		my_check_aff(char **wordtab,
			     t_header *header,
			     t_file_info *fi);
int		my_epure_str(char *str);
int		my_get_op(char *instruction);
unsigned char	my_byte_code(unsigned char args[]);
void		my_fill_args(unsigned char args[],
			     char **wordtab);
int		my_line_is_not_empty(char *str);

#endif /* !VINCENT_H_ */
