/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 22:29:25 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/21 22:29:25 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;

	i = -1;
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	else
		while ((i = i + 1) < ft_strlen(s1))
			result[i] = s1[i];
	result[i] = '\0';
	return (result);
}
