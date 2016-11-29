/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:42:38 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/26 15:42:38 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*cast_s1;
	char	*cast_s2;
	int		i;
	int		n;

	cast_s1 = (char *)s1;
	cast_s2 = (char *)s2;
	i = -1;
	n = -1;
	if (!(result = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	while (s1[i = i + 1])
		result[i] = s1[i];
	while (s2[n = n + 1])
	{
		result[i] = s2[n];
		i++;
	}
	result[i] = '\0';
	return (result);
}
