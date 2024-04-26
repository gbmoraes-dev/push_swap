/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:14:43 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/26 00:15:44 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	a = create_stack(argc - 1, argv);
	if (is_sorted(a))
	{
		destroy_list(a);
		return (1);
	}
	b = new_list();
	index_list(&a);
	if (a->size == 3)
		sort_three(&a);
	else if (a->size == 4)
		sort_four(&a, &b, 0);
	else if (a->size == 5)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	destroy_list(a);
	destroy_list(b);
}
