/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:01:21 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/11 21:25:17 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stack_src, t_stack *stack_dest)
{
	t_clist	*first;

	if (!stack_src->stack)
		return ;
	first = stack_src->stack;
	ft_clstdelfirst(&stack_src->stack);
	stack_src->size--;
	first->next = first;
	first->prev = first;
	ft_clstadd_front(&stack_dest->stack, first);
	stack_dest->size++;
}

// void	ft_push(t_stack *stack_src, t_stack *stack_dest)
// {
// 	int		number;
// 	t_clist	*new;

// 	if (!stack_src->stack)
// 		return ;
// 	number = stack_src->stack->number;
// 	new = ft_clstnew(number);
// 	if (!new)
// 		ft_exit(stack_src, stack_dest, MEMORY_ERR, NULL);
// 	ft_clstdelfirst(&stack_src->stack);
// 	stack_src->size--;
// 	ft_clstadd_front(&stack_dest->stack, new);
// 	stack_dest->size++;
// }

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
