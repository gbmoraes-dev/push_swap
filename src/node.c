/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:42:50 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/25 20:49:23 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_head(t_list **list, t_node *head)
{
	if (!(*list) || !head)
		return ;
	if (!(*list)->head)
	{
		(*list)->head = head;
		(*list)->tail = head;
		head->next = head;
		head->prev = head;
	}
	else
	{
		head->next = (*list)->head;
		head->prev = (*list)->tail;
		(*list)->head->prev = head;
		(*list)->tail->next = head;
		(*list)->head = head;
	}
	(*list)->size++;
}

void	add_tail(t_list **list, t_node *tail)
{
	if (!(*list))
		*list = new_list();
	if (!(*list)->head)
	{
		(*list)->head = tail;
		(*list)->tail = tail;
		tail->next = tail;
		tail->prev = tail;
	}
	else
	{
		tail->next = (*list)->head;
		tail->prev = (*list)->tail;
		(*list)->head->prev = tail;
		(*list)->tail->next = tail;
		(*list)->tail = tail;
	}
	(*list)->size++;
}

t_node	*remove_head(t_list **list)
{
	t_node	*node_to_remove;

	if (!(*list) || !(*list)->head)
		return (NULL);
	node_to_remove = (*list)->head;
	if ((*list)->head == (*list)->tail)
	{
		(*list)->head = NULL;
		(*list)->tail = NULL;
	}
	else
	{
		(*list)->head = node_to_remove->next;
		(*list)->head->prev = (*list)->tail;
		(*list)->tail->next = (*list)->head;
	}
	(*list)->size--;
	return (node_to_remove);
}

t_node	*remove_tail(t_list **list)
{
	t_node	*node_to_remove;

	if (!(*list) || !(*list)->head || !(*list)->tail
		|| (*list)->head == (*list)->tail)
		return (NULL);
	node_to_remove = (*list)->tail;
	if ((*list)->head == (*list)->tail)
	{
		(*list)->head = NULL;
		(*list)->tail = NULL;
	}
	else
	{
		(*list)->tail->prev->next = (*list)->head;
		(*list)->head->prev = (*list)->tail->prev;
		(*list)->tail = (*list)->tail->prev;
	}
	(*list)->size--;
	return (node_to_remove);
}
