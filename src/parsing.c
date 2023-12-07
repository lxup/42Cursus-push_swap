/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:15:43 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/07 21:25:59 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

static void	*check_duplicate(t_stack *stack)
{
	int		i;
	int		*array;
	t_clist	*first;

	array = (int *)malloc(sizeof(int) * stack->size);
	if (!stack || !array)
		return (free(array), NULL);
	first = stack->stack;
	i = -1;
	while (++i < stack->size && first->next && first->next != stack->stack)
	{
		array[i] = first->number;
		if (has_duplicate(array, i, array[i]))
			return (free(array), \
				ft_exit(stack, NULL, ARGS_ERR, "Duplicate numbers"));
		first = first->next;
	}
	if (first->next == stack->stack)
	{
		array[i] = first->number;
		if (has_duplicate(array, i, array[i]))
			return (free(array), \
				ft_exit(stack, NULL, ARGS_ERR, "Duplicate numbers"));
	}
	return (free(array), NULL);
}

static int	check_str(char *str)
{
	int	i;
	int	int_count;

	i = 0;
	int_count = 0;
	while (str && str[i])
	{
		if (!is_whitespace(str[i]) && !ft_isdigit(str[i]) \
			&& str[i] != '-' && str[i] != '+')
			return (0);
		if (ft_isdigit(str[i]))
			int_count++;
		i++;
	}
	if (!int_count)
		return (0);
	return (1);
}

static void	get_numbers(t_stack *stack_a, char **buffer)
{
	int		i;
	t_clist	*new;

	i = 0;
	while (buffer[i])
	{
		if (!check_str(buffer[i]))
		{
			ft_free_matrix(buffer);
			ft_exit(stack_a, NULL, ARGS_ERR, "Some character aren't allowed");
		}
		new = ft_clstnew(ft_atoi(buffer[i]));
		if (!new)
		{
			ft_free_matrix(buffer);
			ft_exit(stack_a, NULL, MEMORY_ERR, NULL);
		}
		ft_clstadd_back(&stack_a->stack, new);
		stack_a->size++;
		new = NULL;
		i++;
	}
}

void	parsing(t_stack *stack_a, int ac, char **av)
{
	int		i;
	char	**buffer;

	i = 0;
	while (++i < ac)
	{
		buffer = ft_split(av[i], ' ');
		if (!buffer)
			ft_exit(NULL, NULL, MEMORY_ERR, NULL);
		get_numbers(stack_a, buffer);
		ft_free_matrix(buffer);
	}
	check_duplicate(stack_a);
}
