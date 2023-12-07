/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:25:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/07 21:12:54 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_clst(t_clist **head, char *name)
{
	t_clist	*first;

	if (!*head)
		return ;
	first = *head;
	ft_putstr_fd("|========== ", 1);
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" ==========|\n", 1);
	while (first->next && first->next != *head)
	{
		ft_putnbr_fd(first->number, 1);
		ft_putchar_fd('\n', 1);
		first = first->next;
	}
	if (first->next == *head)
	{
		ft_putnbr_fd(first->number, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_print_clst(&stack_a->stack, "a");
	ft_putstr_fd("size: ", 1);
	ft_putnbr_fd(stack_a->size, 1);
	ft_putstr_fd("\n", 1);
	ft_print_clst(&stack_b->stack, "b");
	ft_putstr_fd("size: ", 1);
	ft_putnbr_fd(stack_b->size, 1);
	ft_putstr_fd("\n", 1);
}

void	ft_print_allnodes(t_clist **head, char *name)
{
	t_clist	*first;

	if (!*head)
		return ;
	first = *head;
	printf("|========== STACK %s ==========|\n", name);
	while (first->next && first->next != *head)
	{
		printf("NODE: value->%d, next->%d prev->%d\n\n", first->number, first->next->number, first->prev->number);
		first = first->next;
	}
	if (first->next == *head)
	{
		printf("NODE: value->%d, next->%d prev->%d\n\n", first->number, first->next->number, first->prev->number);
		ft_putchar_fd('\n', 1);
	}
	printf("|========== STACK %s ==========|\n", name);
}
