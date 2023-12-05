/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:04:06 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/05 22:18:57 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_clst(t_stack *stack, char *name)
{
	int	i;
	t_clist	*current;
	
	current = stack->stack;
	ft_putstr_fd(name, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("-\n", 1);
	i = 0;
	while (i++ < stack->size && current)
	{
		ft_putnbr_fd(current->number, 1);
		ft_putstr_fd("and index ", 1);
		ft_putnbr_fd(current->index, 1);
		ft_putchar_fd('\n', 1);
		current = current->next;
	}
}

void	ft_init_clst(t_stack *stack, int ac, char **av)
{
	int	i;

	i = 0;
	while (i++ < ac)
	{
		ft_clstadd_back(&stack->stack, ft_clstnew(ft_atoi(av[i]), stack->size));
		stack->size++;
	}
}

void	ft_init_stacks(t_stack *stack)
{
	stack->stack = NULL;
	stack->size = 0;
}

void	ft_clstfree(t_stack *stack)
{
	int	i;
	t_clist	*current;
	t_clist	*backup;
	
	current = stack->stack;
	i = 0;
	while (i++ < stack->size && current)
	{
		backup = current->next;
		free(current);
		current = backup;
	}
}

int	main(int ac, char **av)
{
	(void)ac, (void)av;
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac-- < 2)
		return (1);
	ft_init_stacks(&stack_a);
	ft_init_stacks(&stack_a);
	ft_init_clst(&stack_a, ac, av);
	ft_print_clst(&stack_a, "a");
	ft_clstfree(&stack_a);
	return (0);
}