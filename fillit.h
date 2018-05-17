/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:05:40 by mguyout           #+#    #+#             */
/*   Updated: 2016/12/16 19:59:15 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct	s_struct
{
	char		**res;
	int			minx;
	int			maxx;
	int			miny;
	int			maxy;
	int			size;
	int			height;
	int			width;
	int			x;
	int			y;
	int			c;
	int			i;
}				t_struct;

int				main(int argc, char **argv);
int				check_file(const char *str, int x, int y, int i);
int				square_size(int bloc);
int				solve(char ***map, t_struct *data, int i);
int				check_slot(char ***map, t_struct *data, int x, int y);
char			*ft_convert_string(int fd, char **argv);
char			**create_res(int i, int j, int size);
char			***check_bloc(char *str, int i, int j, int k);
char			***create_map(char *str, int i, int j, int k);
char			***init_map(int i, int j, char *str);
void			check_bloc_core(char ***map, int *connection, int *bloc, int i);
void			free_map(char ***map);
void			free_res(char **res);
void			resolve(char ***map, int i, int j);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			put_tetris(char ***map, t_struct *data, char c);
void			print_res(char **res, int i, int j);
void			get_tetris_info(char ***map, t_struct *data);
void			get_tetris_info_core(t_struct *data, int j, int k);
void			print_result(char **map, int i);
void			erase(char ***map, t_struct *data, int x, int y);
#endif
