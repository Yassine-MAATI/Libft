/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaati <ymaati@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:06:38 by ymaati            #+#    #+#             */
/*   Updated: 2026/11/05 20:19:16 by ymaati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	**freeup(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (NULL);
}

static char	**fillup(char **arr, char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			arr[i] = ft_substr(s, 0, len);
			if (!arr[i])
				return (freeup(arr, i));
			i++;
			s += len;
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc (sizeof(char *) * (counter(s, c) + 1));
	if (!arr)
		return (NULL);
	return (fillup(arr, s, c));
}
