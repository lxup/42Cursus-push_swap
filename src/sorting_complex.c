/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:19:00 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/17 13:35:08 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_target(t_stack *stack, t_clist *target, char name)
{
	while (stack->stack != target)
	{
		if (name == 'a')
		{
			if (target->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (name == 'b')
		{
			if (target->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

static void	move(t_stack *a, t_stack *b)
{
	t_clist	*cheapest_node;

	cheapest_node = get_cheapest(b);
	if (cheapest_node->above_median \
		&& cheapest_node->target_node->above_median)
		while (a->stack != cheapest_node->target_node \
			&& b->stack != cheapest_node)
			rr(a, b, 1);
	else if (!cheapest_node->above_median \
		&& !cheapest_node->target_node->above_median)
		while (a->stack != cheapest_node->target_node \
			&& b->stack != cheapest_node)
			rrr(a, b, 1);
	set_current_index(a);
	set_current_index(b);
	rotate_to_target(b, cheapest_node, 'b');
	rotate_to_target(a, cheapest_node->target_node, 'a');
	pa(a, b, 1);
}

void	complex_sort(t_stack *a, t_stack *b)
{
	t_clist	*smallest;

	while (a->size > 3)
		pb(a, b, 1);
	three_sort(a);
	while (b->size || b->stack)
	{
		init_sort(a, b);
		move(a, b);
	}
	set_current_index(a);
	smallest = find_smallest_node(a);
	if (smallest->above_median)
		while (a->stack != smallest)
			ra(a, 1);
	else
		while (a->stack != smallest)
			rra(a, 1);
}
