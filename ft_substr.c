/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaati <ymaati@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:53:09 by ymaati            #+#    #+#             */
/*   Updated: 2026/11/05 20:12:17 by ymaati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	clen;
	char	*sub;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = malloc (sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (ft_strlen(s) < start)
		clen = 0;
	else if (ft_strlen(s) - start < len)
		clen = (ft_strlen(s) - start);
	else
		clen = len;
	sub = malloc (sizeof(char) * (clen + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], clen + 1);
	return (sub);
}
