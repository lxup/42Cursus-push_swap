/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:23:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 18:17:48 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clist	*ft_clstnew(int number)
{
	t_clist	*new_lst;

	new_lst = (t_clist *)malloc(sizeof(t_clist));
	if (!new_lst)
		return (NULL);
	new_lst->number = number;
	new_lst->current_index = -1;
	new_lst->operation_cost = 0;
	new_lst->cheapest = 0;
	new_lst->target_node = NULL;
	new_lst->above_median = -1;
	new_lst->next = new_lst;
	new_lst->prev = new_lst;
	return (new_lst);
}
