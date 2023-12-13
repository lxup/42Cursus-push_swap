/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:04:06 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 20:37:05 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	parse_command(t_stack *a, t_stack *b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(command, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, 0);
	else
		ft_exit(a, b, CMD_ERR, command);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		len_bkp;
	char	*line;

	if (ac < 2)
		return (*(int *)ft_exit(NULL, NULL, ARGS_ERR, "Need at least 1 args"));
	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	parsing(&stack_a, ac, av);
	len_bkp = stack_a.size;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line || !*line)
			break ;
		parse_command(&stack_a, &stack_b, line);
		free(line);
	}
	if (len_bkp != stack_a.size || !is_sorted(&stack_a.stack))
		return (ft_putstr_fd("KO\n", 2), \
			*(int *)ft_exit(&stack_a, &stack_b, EMPTY_ERR, NULL));
	return (ft_putstr_fd("OK\n", 2), *(int *)ft_exit(&stack_a, &stack_b, 0, NULL));
}
