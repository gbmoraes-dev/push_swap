/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:04:53 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/25 21:05:27 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_five(t_list **a, t_list **b)
{
	if ((*a)->head->index == 0)
	{
		pb(a, b, false);
		sort_four(a, b, 1);
		pa(a, b, false);
	}
	else if ((*a)->head->next->index == 0)
	{
		sa(a, false);
		pb(a, b, false);
		sort_four(a, b, 1);
	}
	else
	{
		if (!is_sorted(*a))
		{
			rra(a, false);
			sort_five(a, b);
		}
	}
	pa(a, b, false);
}
