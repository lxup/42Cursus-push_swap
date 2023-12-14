/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:54:01 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/14 15:37:21 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_stack *stack)
{
	if (!stack->stack)
		return ;
	stack->stack = stack->stack->prev;
}

void	rra(t_stack *a, int print)
{
	ft_rrotate(a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b, int print)
{
	ft_rrotate(b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	ft_rrotate(a);
	ft_rrotate(b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
