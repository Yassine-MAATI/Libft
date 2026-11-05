/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaati <ymaati@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:29:44 by ymaati            #+#    #+#             */
/*   Updated: 2026/11/05 20:18:52 by ymaati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			i;
	long int	ln;

	ln = n;
	i = nlen(n);
	ptr = malloc (sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	if (ln == 0)
		ptr[0] = '0';
	else if (ln < 0)
	{
		ptr[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		ptr[--i] = ((ln % 10) + '0');
		ln /= 10;
	}
	return (ptr);
}
