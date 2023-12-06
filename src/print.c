/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:25:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/06 20:29:52 by lquehec          ###   ########.fr       */
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
	while (first->next != *head)
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

void	ft_print_stacks(t_clist **stack_a, t_clist **stack_b)
{
	ft_print_clst(stack_a, "a");
	ft_print_clst(stack_b, "b");
}