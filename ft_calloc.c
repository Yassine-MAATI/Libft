/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaati <ymaati@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 22:26:50 by ymaati            #+#    #+#             */
/*   Updated: 2026/11/05 20:12:03 by ymaati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	n;

	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	if (nmemb == 0 || size == 0)
		n = 1;
	else
		n = nmemb * size;
	ptr = malloc (n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n);
	return (ptr);
}
