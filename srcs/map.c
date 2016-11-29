/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:30:33 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/11/07 23:30:33 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		read_map(char *fd, t_piece *tetriminos)
{
	char	*buffer;
	int		file;
	int		count;
	ssize_t	bytes;

	count = 0;
	buffer = ft_memalloc(21);
	file = open(fd, O_RDONLY);
	while ((bytes = read(file, buffer, 21)))
	{
		if (validate_size(buffer, bytes) == 0)
			return (0);
		if (validate(buffer, 0) != 1)
			return (0);
		ft_strcpy(tetriminos[count].piece, buffer);
		buffer = ft_memalloc(21);
		tetriminos[count].c = 'A' + count;
		count++;
	}
	if (count == 0)
		return (0);
	tetriminos[count].piece = 0;
	initialize(tetriminos, generate_empty(sq_rt(count * 4)));
	return (1);
}

/*
** Calculate square root of number and return next positive integer
*/

int		sq_rt(int num)
{
	int root;

	root = 1;
	while ((root * root) < num)
	{
		root++;
	}
	return (root);
}

/*
** Generate a map initially set to minimum size possible for number of pieces;
** pass greater size if unsolvable at current size
*/

char	**generate_empty(int size)
{
	char	**map;
	int		row;
	int		column;

	row = -1;
	if (!(map = malloc(sizeof(char*) * (size + 1))))
		return (0);
	while (row++ < size + 1)
		if (!(map[row] = malloc(sizeof(char) * (size + 1))))
			return (0);
	map[size][0] = 0;
	row = -1;
	column = -1;
	while (row++ < (size - 1))
	{
		while (column++ < (size - 1))
			map[row][column] = '.';
		map[row][column] = 0;
		column = -1;
	}
	return (map);
}

int		map_size(char **array)
{
	int j;

	j = 0;
	while (array[0][j])
		j++;
	return (j);
}
