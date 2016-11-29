/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:30:21 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/11/09 14:30:21 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Recursive solving function; takes an array of structs and creates a size 2
** array to store current starting position to attempt solving from.
*/

int		solve(t_piece *tetriminos, int i, char **map)
{
	int coord[2];

	if (is_solved(tetriminos) == 1)
		return (1);
	coord[0] = -1;
	while (coord[0]++ < map_size(map))
	{
		coord[1] = -1;
		while (coord[1]++ < map_size(map))
		{
			if (is_valid(&coord[0], &coord[1], tetriminos[i], map) == 1)
			{
				if (tetriminos[i].flag != 1)
				{
					place_piece(tetriminos[i], &coord[0], &coord[1], map);
					tetriminos[i].flag = 1;
				}
				if (solve(tetriminos, i + 1, map) == 1)
					return (1);
				remove_piece(tetriminos[i], &coord[0], &coord[1], map);
				tetriminos[i].flag = 0;
			}
		}
	}
	return (0);
}

void	place_piece(t_piece tetrimino, int *row, int *col, char **map)
{
	map[*row + tetrimino.x[0]][*col + tetrimino.y[0]] = tetrimino.c;
	map[*row + tetrimino.x[1]][*col + tetrimino.y[1]] = tetrimino.c;
	map[*row + tetrimino.x[2]][*col + tetrimino.y[2]] = tetrimino.c;
	map[*row + tetrimino.x[3]][*col + tetrimino.y[3]] = tetrimino.c;
}

void	remove_piece(t_piece tetrimino, int *row, int *col, char **map)
{
	map[*row + tetrimino.x[0]][*col + tetrimino.y[0]] = '.';
	map[*row + tetrimino.x[1]][*col + tetrimino.y[1]] = '.';
	map[*row + tetrimino.x[2]][*col + tetrimino.y[2]] = '.';
	map[*row + tetrimino.x[3]][*col + tetrimino.y[3]] = '.';
}

int		is_valid(int *row, int *col, t_piece tetrimino, char **map)
{
	int x;
	int y;

	x = *row;
	y = *col;
	while (x <= map_size(map))
	{
		while (y <= map_size(map))
		{
			if (map[*row + tetrimino.x[0]][*col + tetrimino.y[0]] == '.' \
				&& map[*row + tetrimino.x[1]][*col + tetrimino.y[1]] == '.' \
				&& map[*row + tetrimino.x[2]][*col + tetrimino.y[2]] == '.' \
				&& map[*row + tetrimino.x[3]][*col + tetrimino.y[3]] == '.')
				return (1);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int		is_solved(t_piece *tetriminos)
{
	int i;

	i = 0;
	while (tetriminos[i].piece)
	{
		if (tetriminos[i].flag == 0)
			return (0);
		i++;
	}
	return (1);
}
