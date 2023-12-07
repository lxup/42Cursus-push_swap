/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstdelfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:15:53 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/07 18:13:01 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clstdelfirst(t_clist **head)
{
	t_clist	*first;
	t_clist	*second;
	t_clist	*last;

	if (!*head)
		return ;
	first = *head;
	second = first->next;
	last = first->prev;
	if (first == last)
	{
		ft_clstfree_node(first);
		*head = NULL;
		return ;
	}
	second->prev = last;
	last->next = second;
	ft_clstfree_node(first);
	*head = second;
}
