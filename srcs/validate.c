/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:15:24 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/11/05 12:42:53 by pstevens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** 'validate' will receive a trimmed string to identify.
** A trimmed string has no leading or following dots, each \n is converted to
** a dot.
** It looks through the array of 'piece_init' and searches for a match.
** If a match is found, it returns the index of this piece, else returns 1.
*/

int		validate(char *tetrimino, int i)
{
	int ret;

	ret = 0;
	piece_init();
	ft_strcpy(tetrimino, ft_strtrim_c(tetrimino, '#'));
	ft_strcpy(tetrimino, newline_annihilator(tetrimino));
	if (ft_strcmp(tetrimino, g_piece[i]) != 0 && i < 18)
	{
		i++;
		ret = validate(tetrimino, i);
	}
	if (ft_strcmp(tetrimino, g_piece[i]) == 0)
		return (1);
	return (ret);
}

char	*newline_annihilator(char *tetrimino)
{
	int i;

	i = 0;
	while (tetrimino[i])
	{
		if (tetrimino[i] == '\n')
			tetrimino[i] = '.';
		i++;
	}
	return (tetrimino);
}

/*
** Check that lines only contain '.' and '#", end with a new line, and that
** each piece contains proper amount of rows and columns.
** Removed " && string != '\0'" from if statements
*/

int		validate_size(char *string, int bytes)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (string[1] == '\n')
		return (0);
	while (i <= 20 && string[i])
	{
		if (string[i] == '#')
			count++;
		if ((i + 1) % 5 == 0 && string[i] != '\n' && i != 19)
			return (0);
		if (i > 0 && i < 20 && (i + 1) % 5 != 0 && string[i] != '.' \
			&& string[i] != '#')
			return (0);
		i++;
	}
	if (count != 4)
		return (0);
	if (check_newline(string, bytes) == 0)
		return (0);
	return (1);
}

int		check_newline(char *string, int bytes)
{
	if (bytes == 99 && string[20] == '\n')
		return (0);
	if (bytes == 20)
	{
		if (string[19] != '\n')
			return (0);
	}
	else if (bytes == 21)
	{
		if (string[20] != '\n')
			return (0);
	}
	return (1);
}
