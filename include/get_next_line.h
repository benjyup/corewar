/*
** get_next_line.h for get_next_line.h in /home/peixot_b/Depot/CPE/CPE_2015_getnextline
** 
** Made by Peixoto Benjamin
** Login   <peixot_b@epitech.net>
** 
** Started on  Tue Jan 12 15:07:41 2016 Peixoto Benjamin
** Last update Mon Mar 14 13:12:49 2016 Peixoto Benjamin
*/

#ifndef READ_SIZE
# define READ_SIZE (4500)
#endif /* !READ_SIZE */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

char		*get_next_line(const int fd);
static char	*my_new_line(char *line, int i, char *buff, int *begin);

#endif /* !GET_NEXT_LINE_H_ */
