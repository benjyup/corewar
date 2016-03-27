/*
** flo.h for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/include
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Mar 14 12:46:29 2016 vincent mesquita
** Last update Sat Mar 26 19:50:12 2016 Vincent Florian
*/

#ifndef FLO_H_
# define FLO_H_

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

typedef	struct		s_int
{
  struct s_int		*next;
  struct s_int		*prev;
  int			pos;
}			t_int;

typedef struct		s_first
{
  int			ps;
  t_label		*root;
  char			*filename;
  int			line;
}			t_first;

void		my_put_error2(char *who,
			      int line,
			      char *filename,
			      char *error);
t_first		*my_ps(char *filename, int i);
int		my_add_to_end_label_list(t_label *root, char *label, int pos, int i);
int		my_add_to_end_int_list(t_int *root, int pos);
t_int		*pars_first(t_first *first);
t_label		*my_init_label_list(void);
int		my_check_label(t_label *current, t_first *first, int i);
t_first		*my_init_first_list(void);
t_int		*my_init_int_list(void);
void	my_delete_to_begin_int_list(t_int *root);

#endif /* !FLO_H_ */
