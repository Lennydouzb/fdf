/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:49:24 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/05 15:45:18 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	coef;
	int	k;
	int	nbr;

	k = 0;
	coef = 1;
	nbr = 0;
	while ((nptr[k] >= 9 && nptr[k] <= 13) || nptr[k] == ' ')
		++k;
	if (nptr[k] == '-' || nptr[k] == '+')
	{
		if (nptr[k] == '-')
			coef *= -1;
		++k;
	}
	while (nptr[k] >= '0' && nptr[k] <= '9')
	{
		nbr = nbr * 10 + nptr[k] - '0';
		++k;
	}
	return (nbr * coef);
}

long	ft_atoi_long(const char *nptr)
{
	long	coef;
	long	k;
	long	nbr;

	k = 0;
	coef = 1;
	nbr = 0;
	while ((nptr[k] >= 9 && nptr[k] <= 13) || nptr[k] == ' ')
		++k;
	if (nptr[k] == '-' || nptr[k] == '+')
	{
		if (nptr[k] == '-')
			coef *= -1;
		++k;
	}
	while (nptr[k] >= '0' && nptr[k] <= '9')
	{
		nbr = nbr * 10 + nptr[k] - '0';
		++k;
	}
	return (nbr * coef);
}

int	ft_atoi_hex(const char *nptr)
{
	int		k;
	int		nbr;

	k = 0;
	nbr = 0;
	if (nptr[k] == '0' && (nptr[k + 1] == 'x' || nptr[k + 1] == 'X'))
		k += 2;
	while ((nptr[k] >= '0' && nptr[k] <= '9') || (nptr[k] >= 'a' && nptr[k] <= 'f')
		|| (nptr[k] >= 'A' && nptr[k] <= 'F'))
	{
		if (nptr[k] >= '0' && nptr[k] <= '9')
			nbr = nbr * 16 + (nptr[k] - '0');
		else if (nptr[k] >= 'a' && nptr[k] <= 'f')
			nbr = nbr * 16 + (nptr[k] - 'a' + 10);
		else if (nptr[k] >= 'A' && nptr[k] <= 'F')
			nbr = nbr * 16 + (nptr[k] - 'A' + 10);
		++k;
	}
	return (nbr);
}