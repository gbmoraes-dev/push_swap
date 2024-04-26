/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:19:24 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/26 00:25:29 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	unsigned int	size;
	t_node			*head;
	t_node			*bigger;
	t_node			*smaller;
	t_node			*tail;
}	t_list;

/*
** Utils
*/

int				is_sorted(t_list *list);
unsigned int	node_max_bits(t_list *list);

/*
** Errors
*/

void			handle_error(t_list *a, t_list *b);
void			handle_checker_error(t_list *a, t_list *b, int *i);

/*
** Stack
*/

void			print_list(t_list *list);
void			index_list(t_list **list);
void			add_head(t_list **list, t_node *head);
void			add_tail(t_list **list, t_node *tail);
void			destroy_list(t_list *list);
t_node			*new_node(int value);
t_node			*remove_head(t_list **list);
t_node			*remove_tail(t_list **list);
t_list			*new_list(void);
t_list			*create_stack(int len, char **input);

/*
** Commands
*/

void			pa(t_list **a, t_list **b, bool print);
void			pb(t_list **a, t_list **b, bool print);
void			sa(t_list **a, bool print);
void			sb(t_list **b, bool print);
void			ss(t_list **a, t_list **b, bool print);
void			ra(t_list **a, bool print);
void			rb(t_list **b, bool print);
void			rr(t_list **a, t_list **b, bool print);
void			rra(t_list **a, bool print);
void			rrb(t_list **b, bool print);
void			rrr(t_list **a, t_list **b, bool print);
void			push(t_list **from, t_list **to);
void			swap(t_list **list);
void			rotate(t_list **list);
void			reverse_rotate(t_list **list);

/*
** Sort algorithms
*/

void			sort_three(t_list **a);
void			sort_four(t_list **a, t_list **b, int index);
void			sort_five(t_list **a, t_list **b);
void			radix_sort(t_list **a, t_list **b);

#endif
