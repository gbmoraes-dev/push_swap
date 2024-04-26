/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:03:23 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/25 21:03:50 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_list **a)
{
	t_node	*biggest;

	biggest = (*a)->bigger;
	if ((*a)->head == biggest)
		ra(a, false);
	else if ((*a)->head->next == biggest)
		rra(a, false);
	if (!is_sorted(*a))
		sa(a, false);
}
