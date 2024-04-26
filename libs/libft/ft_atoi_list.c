/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:54:32 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/25 23:54:42 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_validator(long long n)
{
	return (n <= 2147483647 && n >= -2147483648);
}

static t_int_valid	atoi_error(void)
{
	t_int_valid	err;

	err.err = 1;
	err.value = 0;
	return (err);
}

t_int_valid	ft_atoi_list(const char *nptr)
{
	int			i;
	t_int_valid	n;
	int			minus;

	i = 0;
	n.value = 0;
	n.err = 0;
	minus = 1;
	if (nptr[i] == '-')
	{
		minus = minus * -1;
		i++;
	}
	if (!ft_isdigit(nptr[i]) && !nptr[i])
		return (n.err = 1, n);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i])
			|| !n_validator(((long long)n.value * 10 + (nptr[i] - '0'))
				* minus))
			return (atoi_error());
		n.value = n.value * 10 + (nptr[i] - '0');
		i++;
	}
	return (n.value = n.value * minus, n);
}
