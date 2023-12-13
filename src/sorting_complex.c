/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:19:00 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 18:17:38 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_index(t_stack *stack)
{
	t_clist	*head;
	int		i;
	int		index;

	if (!stack || !stack->stack)
		return ;
	i = -1;
	index = 0;
	head = stack->stack;
	while (++i < stack->size)
	{
		head->current_index = i;
		if (i <= stack->size / 2)
			head->above_median = 1;
		else
			head->above_median = 0;
		head = head->next;
	}
}

t_clist	*find_smallest_node(t_stack *stack)
{
	t_clist *current;
	t_clist	*smallest_node;
	long	smallest;
	int		i;

	if (stack == NULL || stack->stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	current = stack->stack;
	i = -1;
	while (++i < stack->size)
	{
		if (current->number < smallest)
		{
			smallest = current->number;
			smallest_node = current;
		}
		current = current->next;
	}
	return (smallest_node);
}

void	set_target_node(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*current_a;
	t_clist	*current_b;
	t_clist	*target_node;
	long	best_match_index;
	int		i;
	int		j;

	current_b = stack_b->stack;
	i = -1;
	while (++i < stack_b->size)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a->stack;
		j = -1;
		while (++j < stack_a->size)
		{
			if (current_a->number > current_b->number && current_a->number < best_match_index)
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
		current_b = current_b->next;
	}
}

void	set_cheapest(t_stack *stack)
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

void	set_price(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*current_b;
	int		i;

	current_b = stack_b->stack;
	i = -1;
	while (++i < stack_b->size)
	{
		current_b->operation_cost = current_b->current_index;
		if (!current_b->above_median)
			current_b->operation_cost = stack_b->size - (current_b->current_index);
		if (current_b->target_node->above_median)
			current_b->operation_cost += current_b->target_node->current_index;
		else
			current_b->operation_cost += stack_a->size - (current_b->target_node->current_index);
		current_b = current_b->next;
	}
}

void	init_sort(t_stack *stack_a, t_stack *stack_b)
{
	set_current_index(stack_a);
	set_current_index(stack_b);
	set_target_node(stack_a, stack_b);
	// ft_print_clst(&stack_b->stack, "b");
	set_price(stack_a, stack_b);
	set_cheapest(stack_b);
}

t_clist	*return_cheapest(t_stack *stack)
{
	int	i;
	t_clist	*current;

	i = -1;
	current = stack->stack;
	if (current == NULL)
		return (NULL);
	while (++i < stack->size)
	{
		if (current->cheapest)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static void	rotate_both(t_stack *a,
						t_stack *b,
						t_clist *cheapest_node)
{
	while (a->stack != cheapest_node->target_node
		&& b->stack != cheapest_node)
		rr(a, b);
	set_current_index(a);
	set_current_index(b);
}

static void	reverse_rotate_both(t_stack *a,
								t_stack *b,
								t_clist *cheapest_node)
{
	while (a->stack != cheapest_node->target_node
		&& b->stack != cheapest_node)
		rrr(a, b);
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
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}

static void	make_moves(t_stack *a, t_stack *b)
{
	t_clist	*cheapest_node;

	cheapest_node = return_cheapest(b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*smallest;

	while (stack_a->size > 3)
		pb(stack_a, stack_b);
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
			ra(stack_a);
	else
		while (stack_a->stack != smallest)
			rra(stack_a);
}
