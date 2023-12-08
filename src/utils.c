/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:17:01 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/08 19:17:10 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_smallest(t_clist **head, t_number *smallest)
{
	t_clist		*first;
	int			i;

	if (!*head)
		return ;
	first = *head;
	smallest->value = first->number;
	smallest->index = 0;
	i = 0;
	while (first->next != *head)
	{
		if (first->number < smallest->value)
		{
			smallest->value = first->number;
			smallest->index = i;
		}
		first = first->next;
		i++;
	}
	if (first->next == *head)
		if (first->number < smallest->value)
		{
			smallest->value = first->number;
			smallest->index = i;
		}
}
