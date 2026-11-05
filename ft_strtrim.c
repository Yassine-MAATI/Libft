/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaati <ymaati@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:38:47 by ymaati            #+#    #+#             */
/*   Updated: 2026/10/31 00:08:59 by ymaati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lut(int *table, char const *set)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		table[i] = 0;
		i++;
	}
	i = 0;
	while (set[i] != '\0')
	{
		table[(unsigned char) set[i]] = 1;
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		table[256];
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	lut(table, set);
	start = 0;
	while (s1[start] != '\0' && table[(unsigned char) s1[start]])
		start++;
	end = ft_strlen(s1);
	end--;
	while (end > start && table[(unsigned char) s1[end]])
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
