/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:32:00 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/14 15:36:11 by lquehec          ###   ########.fr       */
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

static void	small_sort(t_stack *a, t_stack *b)
{
	t_number	smallest;
	int			rotate;

	while (a->size > 3)
	{
		smallest = ft_find_smallest(a);
		if (smallest.index < a->size / 2)
			rotate = 1;
		else
			rotate = -1;
		while (a->stack->number != smallest.value)
		{
			if (rotate == 1)
				ra(a, 1);
			else
				rra(a, 1);
		}
		pb(a, b, 1);
	}
	three_sort(a);
	while (b->size >= 1)
		pa(a, b, 1);
}

void	sorting(t_stack *a, t_stack *b)
{
	if (a->size < 2)
		ft_exit(a, NULL, 0, NULL);
	if (a->size == 2)
		sa(a, 1);
	else if (a->size == 3)
		three_sort(a);
	else if (a->size <= SMALL_SORT_LIMIT)
		small_sort(a, b);
	else
		complex_sort(a, b);
}
