/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:45:38 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/14 16:35:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node_sub(t_stack *a, t_clist *current_b)
{
	t_clist	*current_a;
	t_clist	*target_node;
	long	target_number;
	int		j;

	target_number = LONG_MAX;
	current_a = a->stack;
	j = -1;
	while (++j < a->size)
	{
		if (current_a->number > current_b->number \
			&& current_a->number < target_number)
		{
			target_number = current_a->number;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	if (target_number == LONG_MAX)
		current_b->target_node = find_smallest_node(a);
	else
		current_b->target_node = target_node;
}

static void	set_target_node(t_stack *a, t_stack *b)
{
	t_clist	*current_b;
	int		i;

	current_b = b->stack;
	i = -1;
	while (++i < b->size)
	{
		set_target_node_sub(a, current_b);
		current_b = current_b->next;
	}
}

static void	set_cost(t_stack *a, t_stack *b)
{
	t_clist	*current_b;
	int		i;

	current_b = b->stack;
	i = -1;
	while (++i < b->size)
	{
		current_b->operation_cost = current_b->current_index;
		if (!current_b->above_median)
			current_b->operation_cost = b->size - \
				(current_b->current_index);
		if (current_b->target_node->above_median)
			current_b->operation_cost += current_b->target_node->current_index;
		else
			current_b->operation_cost += a->size - \
				(current_b->target_node->current_index);
		current_b = current_b->next;
	}
}

static void	set_cheapest(t_stack *stack)
{
	long	cheapest_operation;
	t_clist	*cheapest_node;
	t_clist	*current;
	int		i;

	if (stack == NULL || stack->stack == NULL)
		return ;
	cheapest_operation = LONG_MAX;
	current = stack->stack;
	i = -1;
	while (++i < stack->size)
	{
		if (current->operation_cost < cheapest_operation)
		{
			cheapest_operation = current->operation_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_sort(t_stack *a, t_stack *b)
{
	set_current_index(a);
	set_current_index(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
