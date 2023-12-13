/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:24:41 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 19:43:06 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_clist	*first;
	t_clist	*second;
	t_clist	*third;
	t_clist	*last;

	if (!stack || !stack->stack)
		return ;
	if (stack->size == 2)
	{
		ft_rotate(stack);
		return ;
	}
	first = stack->stack;
	second = first->next;
	third = second->next;
	last = first->prev;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = last;
	third->prev = first;
	last->next = second;
	stack->stack = second;
}

void	sa(t_stack *stack_a, int print)
{
	ft_swap(stack_a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack_b, int print)
{
	ft_swap(stack_b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
