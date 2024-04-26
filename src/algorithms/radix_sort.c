/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:05:35 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/25 21:07:21 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	sort_b(t_list **a, t_list **b, unsigned int bits, unsigned int max)
{
	unsigned int	initial_size;

	initial_size = (*b)->size;
	while (initial_size-- && bits <= max && !is_sorted(*a))
	{
		if ((*b)->head->index >> bits & 1)
			pa(a, b, false);
		else
			rb(b, false);
	}
	if (is_sorted(*a))
	{
		while ((*b)->size)
			pa(a, b, false);
	}
}

void	radix_sort(t_list **a, t_list **b)
{
	unsigned int	bits;
	unsigned int	max;
	unsigned int	initial_size;

	bits = 0;
	max = node_max_bits(*a);
	initial_size = (*a)->size;
	while (bits <= max && !is_sorted(*a))
	{
		initial_size = (*a)->size;
		while (initial_size-- && !is_sorted(*a))
		{
			if ((*a)->head->index >> bits & 1)
				ra(a, false);
			else
				pb(a, b, false);
		}
		bits++;
		sort_b(a, b, bits, max);
	}
	while ((*b)->size)
		pa(a, b, false);
}
