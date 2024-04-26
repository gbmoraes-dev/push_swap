/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:51:18 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/25 20:54:58 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_list **list)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!(*list) || !(*list)->head || !(*list)->tail
		|| (*list)->head == (*list)->tail || !(*list)->head->next)
		return ;
	first_node = remove_head(list);
	second_node = remove_head(list);
	add_head(list, first_node);
	add_head(list, second_node);
}

void	sa(t_list **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_list **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
