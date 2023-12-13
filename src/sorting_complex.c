/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:19:00 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 19:45:33 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack *a,
						t_stack *b,
						t_clist *cheapest_node)
{
	while (a->stack != cheapest_node->target_node
		&& b->stack != cheapest_node)
		rr(a, b, 1);
	set_current_index(a);
	set_current_index(b);
}

static void	reverse_rotate_both(t_stack *a,
								t_stack *b,
								t_clist *cheapest_node)
{
	while (a->stack != cheapest_node->target_node
		&& b->stack != cheapest_node)
		rrr(a, b, 1);
	set_current_index(a);
	set_current_index(b);
}

void	finish_rotation(t_stack *stack,
						t_clist *top_node,
						char stack_name)
{
	while (stack->stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}	
	}
}

static void	make_moves(t_stack *a, t_stack *b)
{
	t_clist	*cheapest_node;

	cheapest_node = get_cheapest(b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, 1);
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*smallest;

	while (stack_a->size > 3)
		pb(stack_a, stack_b, 1);
	three_sort(stack_a);
	while (stack_b->size)
	{
		init_sort(stack_a, stack_b);
		make_moves(stack_a, stack_b);
	}
	set_current_index(stack_a);
	smallest = find_smallest_node(stack_a);
	if (smallest->above_median)
		while (stack_a->stack != smallest)
			ra(stack_a, 1);
	else
		while (stack_a->stack != smallest)
			rra(stack_a, 1);
}
