/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:04:06 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/06 20:50:02 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a, (void)stack_b;
	
}

int	main(int ac, char **av)
{
	(void)ac, (void)av;
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (1);
	ft_init_stacks(&stack_a);
	ft_init_stacks(&stack_b);
	parsing(&stack_a, ac, av);
	// push_swap(&stack_a, &stack_b);
	// ft_print_clst(&stack_a.stack, "a");
	// ft_print_clst(&stack_b.stack, "b");
	// pb(&stack_a, &stack_b);
	// ft_print_clst(&stack_a.stack, "a");
	// ft_print_clst(&stack_b.stack, "b");
	// pa(&stack_a, &stack_b);
	// ft_print_clst(&stack_a.stack, "a");
	// ft_print_clst(&stack_b.stack, "b");
	sorting(&stack_a, &stack_b);
	ft_print_stacks(&stack_a.stack, &stack_b. stack);
	return (*(int *)ft_exit(&stack_a, &stack_b, 0, NULL));
}