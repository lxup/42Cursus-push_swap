/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:32:00 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/06 21:25:03 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a, (void)stack_b;
}

void	three_sort(t_stack *stack)
{
	int		first;
	int		second;
	int		third;

	first = stack->stack->number;
	second = stack->stack->next->number;
	third = stack->stack->prev->number;
	if (is_in_range(third, first, second))
	{
		rra(stack);
		sa(stack);
	}
	else if (is_in_range(third, second, first))
		ra(stack);
	else if (is_in_range(first, third, second))
		rra(stack);
	else if (is_in_range(first, second, third))
		sa(stack);
	else if (is_in_range(second, third, first))
	{
		sa(stack);
		rra(stack);
	}
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a, (void)stack_b;
	pb(stack_a, stack_b);
	if (stack_a->size > 4)
		pb(stack_a, stack_b);
	three_sort(stack_a);	
}

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(&stack_a->stack))
		return ;
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		three_sort(stack_a);
	else if (stack_a->size <= SMALL_SORT_LIMIT)
		small_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
}