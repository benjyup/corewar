/*
** op.h for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Wed Mar 16 15:32:11 2016 vincent mesquita
** Last update Fri Mar 25 16:49:24 2016 vincent mesquita
*/

#ifndef _OP_H_
# define _OP_H_

# define MEM_SIZE		(6*1024)
# define IDX_MOD		512
# define MAX_ARGS_NUMBER	4

# define COMMENT_CHAR		'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

/*
** regs
*/

#define REG_NUMBER		16  /* r1 <--> rx */

/*
**
*/

typedef char			args_type_t;

# define T_REG			1  /* registre */
# define T_DIR			2  /* directe  (ld  #1, cr1  met 1 dans r1) */
# define T_IND			4  /* indirecte toujours relatif
				      ( ld 1, r1 met ce qu'il y a l'adress (1 + pc)
				      dans r1 (4 octecs )) */
# define T_LAB			8  /* LABEL */

typedef struct			s_op
{
  char				*mnemonique;
  char				nbr_args;
  args_type_t			type[MAX_ARGS_NUMBER];
  char				code;
  int				nbr_cycles;
  char				*comment;
}				t_op;

/*
** size
*/

# define REG_SIZE		1
# define DIR_SIZE		4
# define IND_SIZE		2

/*
** op_tab
*/

extern t_op			op_tab[];

/*
** header
*/

# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define COREWAR_EXEC_MAGIC	0xea83f3

typedef struct			s_header
{
  int				magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  int				prog_size;
  char				comment[COMMENT_LENGTH + 1];
}				t_header;

/*
** live
*/

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		5
# define NBR_LIVE		40

#endif /* !OP_H_ */
