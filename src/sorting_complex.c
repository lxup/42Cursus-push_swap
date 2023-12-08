/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:19:00 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/08 21:32:01 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	t_clist	*head;
	int		i;
	int		index;

	if (!stack || !stack->stack)
		return ;
	i = 0;
	index = 0;
	head = stack->stack;
	while (i < stack->size)
	{
		while (head->next != stack->stack)
		{
			head->index = 0;
			head = head->next;
			index++;
		}
		if (head->next == stack->stack)
			head->index = 0;
		
	}
}

void	init_sort(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	
}


void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a, (void)stack_b;
	t_number	smallest;

	while (stack_a->size > 5)
		pb(stack_a, stack_b);
	small_sort(stack_a, stack_b);
	while (stack_b->stack)
	{
		init_sort(stack_a, stack_b);
		
	}
	ft_find_smallest(&stack_a->stack, &smallest);
	while (stack_a->stack->number != smallest.value)
	{
		if (smallest.index <= stack_a->size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	// ft_find_smallest(&stack_a->stack, &smallest);
	// while (stack_a->stack->number != smallest.value)
	// {
	// 	if (smallest.index <= stack_a->size / 2)
	// 		ra(stack_a);
	// 	else
	// 		rra(stack_a);
	// }
	// int	smallest;
	// ft_putstr_fd("COMPLEX SORT", 1);
	// while (stack_a->size > 5)
	// 	pb(stack_a, stack_b);
	// small_sort(stack_a, stack_b);
}
