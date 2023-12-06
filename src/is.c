/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:46:43 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/06 21:14:49 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(int num)
{
	if (num >= INT_MIN && num <= INT_MAX)
		return (1);
	return (0);
}

int	is_in_range(int a, int b, int c)
{
	if (a > b && a < c)
		return (1);
	return (0);
}

int	is_sorted(t_clist **head)
{
	t_clist	*first;

	first = *head;
	if (!*head)
		return (0);
	while (first->next != *head)
	{
		if (first->number > first->next->number)
			return (0);
		first = first->next;
	}
	return (1);
}
