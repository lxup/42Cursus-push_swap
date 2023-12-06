/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:15:43 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/06 20:30:09 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int has_duplicate(int *arr, int size, int num)
{
    int	i;

	i = 0;
	while(i < size)
	{
        if (arr[i] == num)
            return 1;
		i++;
	}
    return 0;
}

int	check_int_presence(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isdigit(str[i]))
		return (1);
	return (0);
}

void	parsing(t_stack *stack_a, int ac, char **av)
{
	int	numbers[ac];
	int	i;
	int	current_number;

	i = 0;
	while (++i < ac)
	{
		if (!check_int_presence(av[i]))
			ft_exit(NULL, NULL, ARGS_ERR, "Int not found inside an argument");
        current_number = ft_atoi(av[i]);
        if (!is_int(current_number))
			ft_exit(NULL, NULL, ARGS_ERR, "Some numbers aren't INT");
        if (has_duplicate(numbers, i - 1, current_number))
            ft_exit(NULL, NULL, ARGS_ERR, "Duplicate numbers");
        numbers[i - 1] = current_number;
    }
	ft_init_clst(stack_a, ac, av);
}