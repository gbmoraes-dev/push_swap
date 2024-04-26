/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:06:34 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/26 00:14:11 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_separator(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	duplicated(t_list *list, int value)
{
	t_node	*current;
	t_node	*next;

	if (!list)
		return (1);
	if (list->size == 0)
		return (0);
	current = list->head;
	while (current->next)
	{
		if (current->value == value)
			return (1);
		next = current->next;
		current = next;
		if (current == list->head)
			break ;
	}
	return (0);
}

static void	build_list(t_list **list, char *s, char c)
{
	int			skip;
	char		*tmp;
	t_int_valid	n;

	skip = 0;
	while (*s)
	{
		if (*s != c)
		{
			skip = find_separator(s, c);
			tmp = ft_substr(s, 0, skip);
			n = ft_atoi_list(tmp);
			free(tmp);
			if (n.err)
				handle_error(*list, NULL);
			if (duplicated(*list, n.value))
				handle_error(*list, NULL);
			add_tail(list, new_node(n.value));
			s += skip;
			continue ;
		}
		s++;
		if (!ft_isdigit(*s) && (*s) != '-')
			handle_error(*list, NULL);
	}
}

static t_list	*split(char *s, char c)
{
	t_list	*list;

	if (!s || !ft_strlen(s))
		return (NULL);
	list = new_list();
	build_list(&list, s, c);
	return (list);
}

t_list	*create_stack(int len, char **input)
{
	t_list			*list;
	int				i;
	t_int_valid		n;

	list = NULL;
	i = 1;
	if (len == 1)
		list = split(input[1], ' ');
	else
	{
		list = new_list();
		while (i <= len)
		{
			n = ft_atoi_list(input[i]);
			if (n.err || !ft_strlen(input[i]))
				handle_error(list, NULL);
			if (duplicated(list, n.value))
				handle_error(list, NULL);
			add_tail(&list, new_node(n.value));
			i++;
		}
	}
	return (list);
}
