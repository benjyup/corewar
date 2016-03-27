/*
** asm.h for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/include
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Mar 14 12:59:53 2016 vincent mesquita
** Last update Sun Mar 27 21:33:45 2016 Vincent Florian
*/

#ifndef ASM_H_
# define ASM_H_

# include "op.h"
# include "my_basics.h"
# define REGISTRE		1
# define DIRECT			2
# define INDIRECT		3
# define INSTRUCTION_NBR	18
# define WRITE_NBR		3
# define ERROR1 "The program's name is to long. It will be truncated.\n"
# define ERROR2 "The program's comment is to long. It will be truncated.\n"

typedef	struct		s_int
{
  struct s_int		*next;
  struct s_int		*prev;
  int			pos;
}			t_int;

typedef struct		s_file_info
{
  char			*filename;
  int			fd;
  int			line_nbr;
  int			name_put;
  int			comment_put;
  int			code_put;
  t_int			*label;
}			t_file_info;

typedef struct		s_instruction_fptr
{
  char			*name;
  int			(*fptr)(char **wordtab,
				t_header *header,
				t_file_info *fi);
}			t_instruction_fptr;

typedef struct		s_write_fptr
{
  unsigned char		flag;
  int			(*fptr)(char *str,
				t_file_info *fi);
}			t_write_fptr;

extern t_write_fptr	write_tab[WRITE_NBR];

typedef union		s_endian_short
{
  unsigned char		c[2];
  short			nb;
}			t_endian_short;


typedef	struct		s_tab_op
{
  char			*op;
  int			o_cod;

}			t_tab_op;

typedef union		s_endian
{
  unsigned char	c[4];
  int			nb;
}			t_endian;

typedef	struct		s_label
{
  struct s_label	*next;
  struct s_label	*prev;
  char			*label;
  int			position;
  int			line;
}			t_label;

typedef struct		s_first
{
  int			ps;
  t_label		*root;
  char			*filename;
  int			line;
}			t_first;

void			my_put_error2(char *who,
				      int line,
				      char *filename,
				      char *error);
t_first			*my_ps(char *filename, int i);
int			my_add_to_end_label_list(t_label *root,
						 char *label,
						 int pos, int i);
int			my_add_to_end_int_list(t_int *root,
					       int pos);
t_int			*pars_first(t_first *first);
t_label			*my_init_label_list(void);
int			my_check_label(t_label *current,
				       t_first *first, int i);
t_first			*my_init_first_list(void);
t_int			*my_init_int_list(void);
void			my_delete_to_begin_int_list(t_int *root);
void			init_struct(t_tab_op *tab);
int			my_check_name2(int *fd, int i);
int			my_strlen_wordtab(char **wordtab);
void			my_args(unsigned char *args,
				char **wordtab, int j);
t_first			*my_ps(char *filename, int i);
int			my_ps_and_label(char *line,
					t_tab_op tab[8],
					int *i, t_first *first);
int			my_strcomp_label(char *s1, char *s2);
char			**my_delete_label(char **wordtab);
int			mine_is_a_label(char *str);
int			my_write_index(unsigned char arg,
				       char *str,
				       t_file_info *fi);
int			my_cor_write(char **wordtab,
				     unsigned char args[MAX_ARGS_NUMBER],
				     t_file_info *fi);
int			my_endian(int	nbr);
int			my_endian_short(short nbr);
int			my_get_reg(char *str, t_file_info *fi);
int			my_get_ind(char *str, t_file_info *fi);
int			my_get_dir(char *str, t_file_info *fi, int flag);
int			my_write(int fd, const void *buff, int count);
int			my_write_register(char *str, t_file_info *fi);
int			my_write_direct(char *str, t_file_info *fi);
int			my_write_indirect(char *str, t_file_info *fi);
int			my_args_are_valid(char **wordtab,
					  t_op *op,
					  t_file_info *fi);
void			my_put_error(char *who,
				     t_file_info *fi,
				     char *error);
void			my_put_warning(char *who,
				       t_file_info *fi,
				       char *error);
int			my_asm(char *filename);
int			my_strcomp_asm(char *str);
void			my_epure_tabulation(char *str);
char			*my_strcat2(char *dest, char *src);
int			my_fill_tab(char tab[], int size, char *str);
int			my_check_live(char **wordtab,
				      t_header *header,
				      t_file_info *fi);
int			my_check_name(char **wordtab,
				      t_header *header,
				      t_file_info *fi);
int			my_check_comment(char **wordtab,
					 t_header *header,
					 t_file_info *fi);
int			my_check_ld(char **wordtab,
				    t_header *header,
				    t_file_info *fi);
int			my_check_st(char **wordtab,
				    t_header *header,
				    t_file_info *fi);
int			my_check_add(char **wordtab,
				     t_header *header,
				     t_file_info *fi);
int			my_check_sub(char **wordtab,
				     t_header *header,
				     t_file_info *fi);
int			my_check_and(char **wordtab,
				     t_header *header,
				     t_file_info *fi);
int			my_check_or(char **wordtab,
				    t_header *header,
				    t_file_info *fi);
int			my_check_xor(char **wordtab,
				     t_header *header,
				     t_file_info *fi);
int			my_check_zjmp(char **wordtab,
				      t_header *header,
				      t_file_info *fi);
int			my_check_ldi(char **wordtab,
				     t_header *header,
				     t_file_info *fi);
int			my_check_sti(char **wordtab,
				     t_header *header,
				     t_file_info *fi);
int			my_check_fork(char **wordtab,
				      t_header *header,
				      t_file_info *fi);
int			my_check_lld(char **wordtab,
				     t_header *header,
				     t_file_info *fi);
int			my_check_lldi(char **wordtab,
				      t_header *header,
				      t_file_info *fi);
int			my_check_lfork(char **wordtab,
				       t_header *header,
				       t_file_info *fi);
int			my_check_aff(char **wordtab,
				     t_header *header,
				     t_file_info *fi);
int			my_epure_str(char *str);
int			my_get_op(char *instruction);
unsigned char		my_byte_code(unsigned char args[]);
void			my_fill_args(unsigned char args[],
				     char **wordtab);
int			my_line_is_not_empty(char *str);

#endif /* !ASM_H_ */
