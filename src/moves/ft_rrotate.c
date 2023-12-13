/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:54:01 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 19:42:39 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_stack *stack)
{
	if (!stack->stack)
		return ;
	stack->stack = stack->stack->prev;
}

void	rra(t_stack *stack_a, int print)
{
	ft_rrotate(stack_a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack_b, int print)
{
	ft_rrotate(stack_b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
