/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:52:26 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/28 11:52:26 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mylog(int num)
{
	int i;
	int	j;

	i = 1;
	j = 0;
	if (num == -2147483648)
		return (11);
	if (num < 0)
	{
		j = 1;
		num = (num * -1);
	}
	while (num >= 10)
	{
		i++;
		num = (num / 10);
	}
	return (i + j);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = (ft_mylog(n) - 1);
	if (!(str = ft_memalloc(sizeof(char) * ft_mylog(n) + 1)))
		return (0);
	str[ft_mylog(n)] = '\0';
	if (n == -2147483648)
		ft_strcpy(str, "-2147483648");
	if (n < 0 && n != -2147483648)
	{
		str[0] = '-';
		n = (n * -1);
	}
	while (n >= 10)
	{
		str[i] = (n % 10 + 48);
		i--;
		n = (n / 10);
	}
	if (n < 10 && n != -2147483648)
		str[i] = (n % 10 + 48);
	return (str);
}
