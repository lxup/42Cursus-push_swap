/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:04:06 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/17 15:49:12 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	read_to_end_file(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
}

static int	parse_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b, 0);
	else if (!ft_strcmp(cmd, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(a, b, 0);
	else
		return (0);
	return (1);
}

static void	parse_cmd_error(t_stack *a, t_stack *b, char *cmd, int fd)
{
	free(cmd);
	read_to_end_file(fd);
	ft_exit(a, b, CMD_ERR, NULL);
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
		if (!parse_cmd(&stack_a, &stack_b, line))
			parse_cmd_error(&stack_a, &stack_b, line, STDIN_FILENO);
		free(line);
	}
	if (len_bkp != stack_a.size || !is_sorted(&stack_a.stack))
		return (ft_putstr_fd("KO\n", 2), \
			*(int *)ft_exit(&stack_a, &stack_b, EMPTY_ERR, NULL));
	return (ft_putstr_fd("OK\n", 2), \
		*(int *)ft_exit(&stack_a, &stack_b, 0, NULL));
}
