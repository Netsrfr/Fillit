/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:15:03 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/10/30 13:24:09 by pstevens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_piece
{
	char	*piece;
	char	c;
	int		x[4];
	int		y[4];
	int		flag;
}					t_piece;
char				*g_piece[20];

/*
** main.c
*/

int					check_empty(char *fd);

/*
** map.c
*/

int					read_map(char *fd, t_piece *tetriminos);
int					sq_rt(int num);
char				**generate_empty(int size);
int					map_size(char **array);
int					calculate_size(int count);

/*
** piece_init.c
*/

void				piece_init(void);
t_piece				*array_init(void);

/*
** solve.c
*/

int					solve(t_piece *tetriminos, int i, char **maptest);
int					is_valid(int *row, int *col, t_piece tetrimino, char **map);
void				place_piece
					(t_piece tetrimino, int *row, int *col, char **map);
void				remove_piece
					(t_piece tetrimino, int *row, int *col, char **map);
int					is_solved(t_piece *tetriminos);

/*
** tetriminos.c
*/

void				print_map(char **map);
void				initialize(t_piece *tetriminos, char **map);
void				init_coords(t_piece *tetriminos);
void				negate_offset(t_piece *tetriminos);
void				map_del(char **map, int size);

/*
** validate.c
*/

int					validate(char *tetrimino, int i);
char				*newline_annihilator(char *tetrimino);
int					validate_size(char *string, int bytes);
int					check_newline(char *string, int bytes);
#endif
