/*
** corewar.h for corewar in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/include
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Mar 14 12:45:02 2016 vincent mesquita
** Last update Sun Mar 27 21:40:45 2016 Vincent Florian
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include "op.h"
# include "my_basics.h"

# define	MAX_CHAMP	4

# define	LIVE_MSG	"le joueur %i(%s) est en vie\n"
# define	WON_MSG		"le joueur %i(%s) a gagne\n"
# define	DRAW		"Draw.\n"

# define	SCHRODINGER	0
# define	ALIVE		1
# define	DEAD		2

# define	LIVE	((proc->instruc->code == 1) ? (1) : (0))
# define	ZJUMP	((proc->instruc->code == 9) ? (1) : (0))
# define	LDI	((proc->instruc->code == 10) ? (1) : (0))
# define	STI	((proc->instruc->code == 11) ? (1) : (0))
# define	FORK	((proc->instruc->code == 12) ? (1) : (0))
# define	LLDI	((proc->instruc->code == 14) ? (1) : (0))
# define	LFORK	((proc->instruc->code == 15) ? (1) : (0))

# define	_GET_SIZE2	((type == T_DIR && !LDI && !STI && !LLDI) \
				 ? (DIR_SIZE) : (IND_SIZE))
# define	GET_SIZE	((type == T_REG) ? (1) : (_GET_SIZE2))

# define	NO_OC	((ZJUMP || FORK || LFORK) ? (2) : (4))

# define	M_SIZE2	((REG_SIZE > IND_SIZE) ? (1) : (IND_SIZE))

# define	M_SIZE	((DIR_SIZE > REG_SIZE && DIR_SIZE > IND_SIZE)	\
			 ? (DIR_SIZE) : (M_SIZE2))
# define	REG_ST_SIZE	4

# define	LD_SIZE	((type == T_DIR) ? (DIR_SIZE) : (IND_SIZE))

typedef	struct	s_int
{
  struct s_int	*next;
  struct s_int	*prev;
  int		pos;
}		t_int;

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

typedef union	s_endian
{
  unsigned char	c[4];
  int		nb;
}		t_endian;

typedef char	t_bool;

typedef struct	s_process
{
  t_op		*instruc;
  int		act;
  int		reg[REG_NUMBER];
  int		pc;
  t_bool	carry;
  int		cycle;
}		t_process;

typedef struct	s_champ
{
  char		*name;
  int		number;
  char		live;
  char		*tmp;
  int		size_ins;
  int		offset;
}		t_champ;

typedef struct	s_mem
{
  char		last_alive;
  unsigned int	nb_live;
  int		cycle_to_die;
  int		cycle_to_dumping;
  t_champ	champ[MAX_CHAMP + 1];
  t_process	*proc;
  int		nb_proc;
  unsigned char	box[MEM_SIZE];
  int		n_opt;
  int		a_opt;
}		t_mem;

typedef struct	s_funct
{
  int	(*funct)(t_mem *, t_process *);
}		t_funct;

extern t_funct	functions[];

int		get_type(int oc_code, int c);

/*
**		VM
**
**			-Initialisation-
*/

int		add_process(t_mem *mem, int nb, int act);
int		add_champ(t_mem *mem, char *name, int nb, int champ);

t_mem		*init_memory();
void		free_memory(t_mem *mem);

int		choose_place(t_mem *mem);
void		my_put_error(char *who,
			     t_file_info *fi,
			     char *error);

/*
**			-Game-
*/
void		print_live_victory(t_mem *mem,
				   int win_or_live,
				   int nb);

int		activate(t_mem *mem, t_process *proc);
void		get_pc(t_mem *mem, t_process *proc);
int		core(t_mem *mem);
int		read_n_char_at_x(t_mem *mem, int n, int x);
int		store_n_char_at_x(t_mem *mem, int res, int n, int x);

/*
**			-Options-
*/

int		dumping(t_mem *mem);
int		option(int arg, char **av, t_mem *mem, int nb_champ);
int		my_dump_opt(t_mem *mem, char *str, char **av);
int		my_n_opt(t_mem *mem, char *str, char **av, int nb_champ);
int		my_a_opt(t_mem *mem, char *str, char **av, int nb_champ);
int		prepare_my_champ(int ac, char **av, t_mem *mem);

/*
**			-Useful-
*/

int		print_help(char *str);

int		my_power_it(int nb, int power);
int		my_endian(int nb);
int		get_real_pos(int pos);
int		get_res_for_type(t_mem *mem, t_process *proc,
				 int place, int *type);
void		*error_pnt(char *str);
int		error_int(char *str);

/*
**			-Function-
*/

int		use_a_function(t_mem *mem, t_process *proc);
int		live(t_mem *mem, t_process *proc);
int		ld(t_mem *mem, t_process *proc);
int		st(t_mem *mem, t_process *proc);
int		add(t_mem *mem, t_process *proc);
int		sub(t_mem *mem, t_process *proc);
int		and(t_mem *mem, t_process *proc);
int		or(t_mem *mem, t_process *proc);
int		xor(t_mem *mem, t_process *proc);
int		zjump(t_mem *mem, t_process *proc);
int		ldi(t_mem *mem, t_process *proc);
int		sti(t_mem *mem, t_process *proc);
int		my_fork(t_mem *mem, t_process *proc);
int		lld(t_mem *mem, t_process *proc);
int		lldi(t_mem *mem, t_process *proc);
int		my_lfork(t_mem *mem, t_process *proc);
int		aff(t_mem *mem, t_process *proc);

#endif /* !COREWAR_H_ */
