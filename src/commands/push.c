/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:50:10 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/25 20:51:01 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_list **to, t_list **from)
{
	t_node	*node;

	node = remove_head(from);
	if (!node)
		return ;
	if (!(*to)->head)
		add_head(to, node);
	else
	{
		if (node != (*to)->head)
			add_head(to, node);
	}
}

void	pa(t_list **a, t_list **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
