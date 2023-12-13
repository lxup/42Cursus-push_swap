/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:10:04 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 16:27:54 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clstfree(t_clist **head)
{
	t_clist	*first;
	t_clist	*tmp;

	if (!head || !*head)
		return ;
	first = *head;
	while (first->next && first->next != *head)
	{
		tmp = first;
		first = first->next;
		free(tmp);
		tmp = NULL;
	}
	if (first->next == *head)
	{
		free(first);
		*head = NULL;
	}
}
