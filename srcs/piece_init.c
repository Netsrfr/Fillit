/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstevens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 14:19:48 by pstevens          #+#    #+#             */
/*   Updated: 2016/11/21 15:37:38 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** The idear here is that we have an array as a global variable.
** Each index holds a string which identifies the piece based off of the pattern
** the function which identifies these pieces should basically ask:
** "is this string a piece within the global variable g_piece? iterate."
** If not found, invalid piece. If found, use it.
*/

void	piece_init(void)
{
	g_piece[0] = ft_strdup("##...##");
	g_piece[1] = ft_strdup("####");
	g_piece[2] = ft_strdup("#....#....#....#");
	g_piece[3] = ft_strdup("#....#...##");
	g_piece[4] = ft_strdup("##...#....#");
	g_piece[5] = ft_strdup("###....#");
	g_piece[6] = ft_strdup("#....###");
	g_piece[7] = ft_strdup("#....#....##");
	g_piece[8] = ft_strdup("##....#....#");
	g_piece[9] = ft_strdup("#..###");
	g_piece[10] = ft_strdup("###..#");
	g_piece[11] = ft_strdup("###...#");
	g_piece[12] = ft_strdup("#...###");
	g_piece[13] = ft_strdup("#....##...#");
	g_piece[14] = ft_strdup("#...##....#");
	g_piece[15] = ft_strdup("##....##");
	g_piece[16] = ft_strdup("#...##...#");
	g_piece[17] = ft_strdup("##..##");
	g_piece[18] = ft_strdup("#....##....#");
}

t_piece	*array_init(void)
{
	int		i;
	t_piece *tetriminos;

	i = 0;
	if (!(tetriminos = (t_piece*)malloc(sizeof(t_piece) * 27)))
		return (0);
	while (i <= 26)
	{
		tetriminos[i].piece = (char *)malloc(sizeof(char) * 17);
		ft_bzero(tetriminos[i].piece, 17);
		i++;
	}
	return (tetriminos);
}
