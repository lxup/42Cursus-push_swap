/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:48:43 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/14 15:37:04 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	if (!stack->stack)
		return ;
	stack->stack = stack->stack->next;
}

void	ra(t_stack *a, int print)
{
	ft_rotate(a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b, int print)
{
	ft_rotate(b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b, int print)
{
	ft_rotate(a);
	ft_rotate(b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
