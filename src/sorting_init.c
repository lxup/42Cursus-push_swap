/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:45:38 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 19:04:47 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node_sub(t_stack *stack_a, t_clist *current_b)
{
	long	best_match_index;
	t_clist	*current_a;
	t_clist	*target_node;
	int		j;

	best_match_index = LONG_MAX;
	current_a = stack_a->stack;
	j = -1;
	while (++j < stack_a->size)
	{
		if (current_a->number > current_b->number \
			&& current_a->number < best_match_index)
		{
			best_match_index = current_a->number;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	if (LONG_MAX == best_match_index)
		current_b->target_node = find_smallest_node(stack_a);
	else
		current_b->target_node = target_node;
}

static void	set_target_node(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*current_b;
	int		i;

	current_b = stack_b->stack;
	i = -1;
	while (++i < stack_b->size)
	{
		set_target_node_sub(stack_a, current_b);
		current_b = current_b->next;
	}
}

static void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*current_b;
	int		i;

	current_b = stack_b->stack;
	i = -1;
	while (++i < stack_b->size)
	{
		current_b->operation_cost = current_b->current_index;
		if (!current_b->above_median)
			current_b->operation_cost = stack_b->size - \
				(current_b->current_index);
		if (current_b->target_node->above_median)
			current_b->operation_cost += current_b->target_node->current_index;
		else
			current_b->operation_cost += stack_a->size - \
				(current_b->target_node->current_index);
		current_b = current_b->next;
	}
}

static void	set_cheapest(t_stack *stack)
{
	long	best_match_value;
	t_clist	*best_match_node;
	t_clist	*current;
	int		i;

	if (stack == NULL || stack->stack == NULL)
		return ;
	best_match_value = LONG_MAX;
	current = stack->stack;
	i = -1;
	while (++i < stack->size)
	{
		if (current->operation_cost < best_match_value)
		{
			best_match_value = current->operation_cost;
			best_match_node = current;
		}
		current = current->next;
	}
	best_match_node->cheapest = 1;
}

void	init_sort(t_stack *stack_a, t_stack *stack_b)
{
	set_current_index(stack_a);
	set_current_index(stack_b);
	set_target_node(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	set_cheapest(stack_b);
}
