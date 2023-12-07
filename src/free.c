/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:44:52 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/07 20:45:41 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_matrix_with_indice(char **matrix, int i)
{
	while (i > 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
