/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:32:00 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 16:44:09 by lquehec          ###   ########.fr       */
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
		sa(stack);
	else if (is_in_range(second, third, first))
	{
		sa(stack);
		rra(stack);
	}
	else if (is_in_range(third, second, first))
		ra(stack);
	else if (is_in_range(third, first, second))
	{
		sa(stack);
		ra(stack);
	}
	else if (is_in_range(first, third, second))
		rra(stack);
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_number	smallest;
	int			rotate;

	while (stack_a->size > 3)
	{
		ft_find_smallest(&stack_a->stack, &smallest);
		if (smallest.index < stack_a->size / 2)
			rotate = 1;
		else
			rotate = -1;
		while (stack_a->stack->number != smallest.value)
		{
			if (rotate == 1)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	three_sort(stack_a);
	while (stack_b->size >= 1)
		pa(stack_a, stack_b);
}

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2)
		ft_exit(stack_a, NULL, 0, NULL);
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		three_sort(stack_a);
	else if (stack_a->size <= SMALL_SORT_LIMIT)
		small_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
}