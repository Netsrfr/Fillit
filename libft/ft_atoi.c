/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:55:17 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/21 16:55:18 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SI(x) (str[i] == x)

int	ft_atoi(const char *str)
{
	int i;
	int neg;
	int result;

	i = 0;
	neg = 1;
	result = 0;
	while (SI(' ') || SI('\t') || SI('\n') || SI('\v') || SI('\r') || SI('\f'))
		i++;
	if (SI('-') && str[i + 1] != '-' && str[i + 1] != '+')
	{
		neg = -neg;
		i++;
	}
	if (SI('+') && str[i + 1] != '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - 48);
		i++;
	}
	return (result * neg);
}
