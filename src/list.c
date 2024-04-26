/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:47:16 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/26 00:06:22 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->size = 0;
	list->head = NULL;
	list->bigger = NULL;
	list->smaller = NULL;
	list->tail = NULL;
	return (list);
}

void	destroy_list(t_list *list)
{
	t_node	*current;
	t_node	*next;

	if (!list)
		return ;
	current = list->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
		if (current == list->head)
			break ;
	}
	free(list);
	list = NULL;
}

void	print_list(t_list *list)
{
	t_node	*current;
	t_node	*next;

	if (!list)
		return ;
	current = list->head;
	while (current->next)
	{
		next = current->next;
		ft_printf("Value: %d, Index: %d\n", current->value, current->index);
		current = next;
		if (current == list->head)
			break ;
	}
	return ;
}
