/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:47:08 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 19:26:40 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clist	*find_smallest_node(t_stack *stack)
{
	t_clist	*current;
	t_clist	*smallest_node;
	long	smallest;
	int		i;

	if (stack == NULL || stack->stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	current = stack->stack;
	i = -1;
	while (++i < stack->size)
	{
		if (current->number < smallest)
		{
			smallest = current->number;
			smallest_node = current;
		}
		current = current->next;
	}
	return (smallest_node);
}

t_number	ft_find_smallest(t_stack *stack)
{
	t_clist		*current;
	t_number	smallest;
	int			i;

	if (!stack || !stack->stack)
		return ((t_number){0, 0});
	current = stack->stack;
	smallest.value = current->number;
	smallest.index = 0;
	i = 0;
	while (i < stack->size)
	{
		if (current->number < smallest.value)
		{
			smallest.value = current->number;
			smallest.index = i;
		}
		current = current->next;
		i++;
	}
	return (smallest);
}

t_clist	*get_cheapest(t_stack *stack)
{
	int		i;
	t_clist	*current;

	i = -1;
	current = stack->stack;
	if (current == NULL)
		return (NULL);
	while (++i < stack->size)
	{
		if (current->cheapest)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	set_current_index(t_stack *stack)
{
	t_clist	*head;
	int		i;
	int		index;

	if (!stack || !stack->stack)
		return ;
	i = -1;
	index = 0;
	head = stack->stack;
	while (++i < stack->size)
	{
		head->current_index = i;
		if (i <= stack->size / 2)
			head->above_median = 1;
		else
			head->above_median = 0;
		head = head->next;
	}
}
