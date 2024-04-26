/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:16:11 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/26 00:16:44 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_error(t_list *a, t_list *b)
{
	ft_printf("Error\n");
	destroy_list(a);
	if (b)
		destroy_list(b);
	exit(0);
}

void	handle_checker_error(t_list *a, t_list *b, int *i)
{
	ft_printf("Error\n");
	destroy_list(a);
	a = NULL;
	if (b)
	{
		destroy_list(b);
		b = NULL;
	}
	if (i)
		free(i);
	i = NULL;
	get_next_line(1);
	exit(0);
}
