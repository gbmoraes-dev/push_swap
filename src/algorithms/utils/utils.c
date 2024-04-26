/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:56:02 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/25 21:02:48 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static t_node	*get_min_node(t_node *node)
{
	t_node	*current;
	t_node	*min;

	if (!node)
		return (NULL);
	min = node;
	current = node->next;
	while (current != node)
	{
		if (current->index == -1 && current->value < min->value)
			min = current;
		current = current->next;
	}
	if (min && min->index == -1)
		return (min);
	else
		return (NULL);
}

int	is_sorted(t_list *list)
{
	t_node	*current;
	t_node	*next;

	if (!list || !list->head || !list->tail
		|| list->head == list->tail)
		return (1);
	current = list->head;
	while (current != list->tail)
	{
		next = current->next;
		if (next->value < current->value)
			return (0);
		current = next;
	}
	return (1);
}

unsigned int	node_max_bits(t_list *list)
{
	unsigned int	i;
	unsigned int	index;

	if (!list || !list->head || !list->tail
		|| list->head == list->tail)
		return (0);
	i = 0;
	index = list->bigger->index;
	while (index)
	{
		i++;
		index >>= 1;
	}
	return (i);
}

void	index_list(t_list **list)
{
	unsigned int	i;
	t_node			*current;
	t_node			*min;

	if (!(*list) || !(*list)->head)
		return ;
	i = 0;
	current = (*list)->head;
	while (i < (*list)->size)
	{
		min = get_min_node(current);
		if (min)
		{
			if (i == 0)
				(*list)->smaller = min;
			min->index = i++;
		}
		current = current->next;
	}
	(*list)->bigger = min;
}
