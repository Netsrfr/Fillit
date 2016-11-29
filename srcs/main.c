/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 20:32:30 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/11/05 12:42:56 by pstevens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int argc, char **argument)
{
	t_piece	*tetriminos;

	if (argc != 2)
	{
		write(1, "usage: fillit input_file\n", 25);
		return (0);
	}
	tetriminos = array_init();
	if (check_empty(argument[1]) == 0 || read_map(argument[1], tetriminos) == 0)
		write(1, "error\n", 6);
	return (0);
}

int	check_empty(char *fd)
{
	int		file_count[2];
	char	buffer[21];

	file_count[1] = 0;
	ft_bzero(buffer, 21);
	if ((file_count[0] = open(fd, O_RDONLY)) == -1)
		return (0);
	while (read(file_count[0], buffer, 21))
		file_count[1]++;
	if (file_count[1] > 26)
		return (0);
	close(file_count[0]);
	file_count[0] = open(fd, O_RDONLY);
	while (file_count[1] >= 1)
	{
		ft_bzero(buffer, 21);
		read(file_count[0], buffer, 21);
		file_count[1]--;
		if (file_count[1] == 0 && buffer[20] == '\n')
			return (0);
	}
	if (buffer[0] == '\n')
		return (0);
	close(file_count[0]);
	return (1);
}
