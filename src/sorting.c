/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:32:00 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 19:44:39 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack *stack)
{
	int		first;
	int		second;
	int		third;

	first = stack->stack->number;
	second = stack->stack->next->number;
	third = stack->stack->prev->number;
	if (is_in_range(first, second, third))
		sa(stack, 1);
	else if (is_in_range(second, third, first))
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (is_in_range(third, second, first))
		ra(stack, 1);
	else if (is_in_range(third, first, second))
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (is_in_range(first, third, second))
		rra(stack, 1);
}

static void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_number	smallest;
	int			rotate;

	while (stack_a->size > 3)
	{
		smallest = ft_find_smallest(stack_a);
		if (smallest.index < stack_a->size / 2)
			rotate = 1;
		else
			rotate = -1;
		while (stack_a->stack->number != smallest.value)
		{
			if (rotate == 1)
				ra(stack_a, 1);
			else
				rra(stack_a, 1);
		}
		pb(stack_a, stack_b, 1);
	}
	three_sort(stack_a);
	while (stack_b->size >= 1)
		pa(stack_a, stack_b, 1);
}

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2)
		ft_exit(stack_a, NULL, 0, NULL);
	if (stack_a->size == 2)
		sa(stack_a, 1);
	else if (stack_a->size == 3)
		three_sort(stack_a);
	else if (stack_a->size <= SMALL_SORT_LIMIT)
		small_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
}
