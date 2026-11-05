/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaati <ymaati@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:40:46 by ymaati            #+#    #+#             */
/*   Updated: 2026/11/05 20:13:44 by ymaati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = malloc (sizeof(char) * (s1len + s2len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, (s1len + s2len + 1));
	ft_strlcat(ptr, s2, (s1len + s2len + 1));
	return (ptr);
}
