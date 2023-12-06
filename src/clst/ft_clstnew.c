/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:23:10 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/06 18:40:33 by lquehec          ###   ########.fr       */
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
	new_lst->next = new_lst;
	new_lst->prev = new_lst;
	return (new_lst);
}
