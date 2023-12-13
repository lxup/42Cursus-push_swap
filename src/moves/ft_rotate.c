/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:48:43 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 20:29:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	if (!stack->stack)
		return ;
	stack->stack = stack->stack->next;
}

void	ra(t_stack *stack_a, int print)
{
	ft_rotate(stack_a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack_b, int print)
{
	ft_rotate(stack_b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
