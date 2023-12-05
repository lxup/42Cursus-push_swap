/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:54:38 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/05 21:54:04 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clstadd_back(t_clist **lst, t_clist *new)
{
	t_clist	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_clstlast(*lst);
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
}