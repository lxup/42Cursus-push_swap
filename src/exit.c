/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:34:55 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/06 19:07:25 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

void	*ft_exit(t_stack *stack_a, t_stack *stack_b, int error, char *param)
{
	if (error < 0)
		ft_error(error, param);
	if (stack_a)
		ft_clstfree(&stack_a->stack);
	if (stack_b)
		ft_clstfree(&stack_b->stack);
	if (error < 0)
		return (exit(EXIT_FAILURE), (void *)EXIT_FAILURE);
	return (exit(EXIT_SUCCESS), (void *)EXIT_SUCCESS);
}
