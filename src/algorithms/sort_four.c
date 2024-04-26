/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:04:03 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/25 21:08:20 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_four(t_list **a, t_list **b, int index)
{
	if ((*a)->head->index == index)
	{
		pb(a, b, false);
		sort_three(a);
		pa(a, b, false);
	}
	else if ((*a)->head->next->index == index)
	{
		sa(a, false);
		pb(a, b, false);
		sort_three(a);
		pa(a, b, false);
	}
	else
	{
		rra(a, false);
		sort_four(a, b, index);
	}
}
