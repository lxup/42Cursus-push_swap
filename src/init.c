/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:32:55 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/07 17:05:48 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_clst(t_stack *stack, int ac, char **av)
{
	int		i;
	t_clist	*new;

	i = 0;
	while (++i < ac)
	{
		new = ft_clstnew(ft_atoi(av[i]));
		if (!new)
			ft_exit(stack, NULL, MEMORY_ERR, NULL);
		ft_clstadd_back(&stack->stack, new);
		stack->size++;
		new = NULL;
	}
}

void	ft_init_stack(t_stack *stack)
{
	stack->stack = NULL;
	stack->size = 0;
}
