/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 16:48:48 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/10/28 16:48:48 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#define TP tetriminos[i].piece

/*
** Initialize coordinates of pieces within their structures
*/

void	print_map(char **map)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (map[row][col])
	{
		while (map[row][col])
		{
			write(1, &map[row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		col = 0;
		row++;
	}
}

void	initialize(t_piece *tetriminos, char **map)
{
	int size;

	init_coords(tetriminos);
	negate_offset(tetriminos);
	while (solve(tetriminos, 0, map) != 1)
	{
		size = map_size(map) + 1;
		map_del(map, map_size(map));
		map = generate_empty(size);
	}
	print_map(map);
}

void	init_coords(t_piece *tetriminos)
{
	int i;
	int j;
	int block;
	int row;

	i = -1;
	while (tetriminos[++i].piece != '\0')
	{
		j = 0;
		block = 0;
		row = 0;
		while (tetriminos[i].piece[j])
		{
			if ((j + 1) % 5 == 0)
				row++;
			if (tetriminos[i].piece[j] == '#')
			{
				tetriminos[i].x[block] = row;
				tetriminos[i].y[block] = j - (row * 5);
				block++;
			}
			j++;
		}
	}
}

/*
** Offsets pieces that would not naturally start at (0, 0) to prevent them from
** generating outside of the map.
*/

void	negate_offset(t_piece *tetriminos)
{
	int i;

	i = 0;
	while (tetriminos[i].piece)
	{
		if (ft_strcmp(TP, g_piece[9]) == 0)
		{
			tetriminos[i].y[0] = tetriminos[i].y[0] + 1;
			tetriminos[i].x[1] = tetriminos[i].x[1] + 1;
			tetriminos[i].y[1] = tetriminos[i].y[1] - 2;
		}
		i++;
	}
}

void	map_del(char **map, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
