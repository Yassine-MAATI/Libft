 * ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaati <ymaati@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:07:36 by ymaati            #+#    #+#             */
/*   Updated: 2026/11/05 20:10:04 by ymaati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	handle_overflow(unsigned long long *res, char c, int sign)
{
	if (*res > 922337203685477580ULL)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	if (*res == 922337203685477580ULL)
	{
		if (sign == 1 && (c - '0') > 7)
			return (-1);
		if (sign == -1 && (c - '0') > 8)
			return (0);
	}
	*res = (*res * 10) + (c - '0');
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int					sign;
	int					check;
	unsigned long long	result;

	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		check = handle_overflow(&result, *nptr, sign);
		if (check <= 0)
			return (check);
		nptr++;
	}
	return ((int)(result * sign));
}
