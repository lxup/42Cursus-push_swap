/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:19:00 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/11 21:35:59 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	get_new_min(t_stack *stack, t_number old_min)
{
	t_clist		*head;
	t_number	new_min;
	int			i;

	new_min.index = 0;
	new_min.value = INT_MAX;
	head = stack->stack;
	i = 0;
	while (i < stack->size)
	{
		if (head->number < new_min.value && head->number > old_min.value)
		{
			new_min.index = old_min.index + 1;
			new_min.value = head->number;
		}
		head = head->next;
		i++;
	}
	return (new_min);
}

void	set_new_min(t_stack *stack, t_number new_min)
{
	t_clist		*head;
	int			i;

	i = -1;
	head = stack->stack;
	while (i < stack->size)
	{
		if (head->number == new_min.value)
		{
			head->index = new_min.index;
			break ;
		}
		head = head->next;
		i++;
	}
}

void	set_index(t_stack *stack)
{
	t_clist		*head;
	t_number	new_min;
	int			index;

	if (!stack || !stack->stack)
		return ;
	index = 0;
	head = stack->stack;
	new_min.index = -1;
	new_min.value = INT_MIN;
	while (index < stack->size)
	{
		new_min = get_new_min(stack, new_min);
		set_new_min(stack, new_min);
		index++;
	}
}

// void	set_index(t_stack *stack)
// {
// 	t_clist	*head;
// 	int		i;
// 	int		index;

// 	if (!stack || !stack->stack)
// 		return ;
// 	i = 0;
// 	index = 0;
// 	head = stack->stack;
// 	while (i < stack->size)
// 	{
// 		while (head->next != stack->stack)
// 		{
// 			head->index = 0;
// 			head = head->next;
// 			index++;
// 		}
// 		if (head->next == stack->stack)
// 			head->index = 0;
		
// 	}
// }

void	init_sort(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
}

int	get_bits_size(t_stack *stack_a)
{
	int		max_bits;

	max_bits = 0;
	while (((stack_a->size - 1) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	t_clist	*head;

	(void)stack_a, (void)stack_b;
	i = 0;
	j = 0;
	size = stack_a->size;
	max_bits = get_bits_size(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			// ft_print_allnodes(&stack_a->stack, "a");
			// ft_print_allnodes(&stack_b->stack, "b");
			head = stack_a->stack;
			if (((head->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->size != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

void	complex_sorte(t_stack *stack_a, t_stack *stack_b)
{
	init_sort(stack_a, stack_b);
	// ft_print_stacks(stack_a, stack_b);
	radix(stack_a, stack_b);
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a, (void)stack_b;
	t_number	smallest;

	while (stack_a->size > 5)
		pb(stack_a, stack_b);
	small_sort(stack_a, stack_b);
	while (stack_b->stack)
	{
		init_sort(stack_a, stack_b);
		radix(stack_a, stack_b);
		// make_moves(stack_a, stack_b);		
	}
	ft_find_smallest(&stack_a->stack, &smallest);
	while (stack_a->stack->number != smallest.value)
	{
		if (smallest.index <= stack_a->size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	// ft_find_smallest(&stack_a->stack, &smallest);
	// while (stack_a->stack->number != smallest.value)
	// {
	// 	if (smallest.index <= stack_a->size / 2)
	// 		ra(stack_a);
	// 	else
	// 		rra(stack_a);
	// }
	// int	smallest;
	// ft_putstr_fd("COMPLEX SORT", 1);
	// while (stack_a->size > 5)
	// 	pb(stack_a, stack_b);
	// small_sort(stack_a, stack_b);
}
