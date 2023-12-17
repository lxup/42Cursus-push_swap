/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:18:26 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/17 15:50:33 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error, char *param)
{
	if (error == EMPTY_ERR)
		return ;
	ft_putstr_fd("Error\n", 2);
	if (error == MEMORY_ERR)
		ft_putstr_fd("No memory left on device.", 2);
	if (error == ARGS_ERR)
		ft_putstr_fd("Arguments-> ", 2);
	if (error == SORT_ERR)
		ft_putstr_fd("Something failed during sort.", 2);
	if (error == CMD_ERR)
		ft_putstr_fd("Command not found.", 2);
	if (param)
		ft_putstr_fd(param, 2);
	ft_putstr_fd("\n", 2);
}
