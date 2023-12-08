/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:04:06 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/08 17:01:14 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (*(int *)ft_exit(NULL, NULL, ARGS_ERR, "Need at least 1 args"));
	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	parsing(&stack_a, ac, av);
	if (is_sorted(&stack_a.stack))
		return (*(int *)ft_exit(&stack_a, &stack_b, 0, NULL));
	sorting(&stack_a, &stack_b);
	// ft_print_stacks(&stack_a, &stack_b);
	return (*(int *)ft_exit(&stack_a, &stack_b, 0, NULL));
}
