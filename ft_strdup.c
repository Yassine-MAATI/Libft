/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaati <ymaati@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 23:18:59 by ymaati            #+#    #+#             */
/*   Updated: 2026/11/05 20:19:24 by ymaati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	n;

	n = ft_strlen(s);
	ptr = malloc (sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, n + 1);
	return (ptr);
}
