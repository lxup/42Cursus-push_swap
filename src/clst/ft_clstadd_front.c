/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:02:25 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/07 18:28:55 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clstadd_front(t_clist **lst, t_clist *new)
{
	t_clist	*first;
	t_clist	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	first = *lst;
	last = ft_clstlast(*lst);
	first->prev = new;
	last->next = new;
	new->prev = last;
	new->next = first;
	*lst = new;
}
