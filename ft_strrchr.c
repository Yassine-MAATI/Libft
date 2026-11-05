/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaati <ymaati@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:24:18 by ymaati            #+#    #+#             */
/*   Updated: 2026/10/30 22:47:34 by ymaati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	while (s_len >= 0)
	{
		if ((unsigned char)s[s_len] == (unsigned char)c)
			return ((char *)&s[s_len]);
		s_len--;
	}
	return (NULL);
}
