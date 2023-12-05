/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:21:21 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/05 22:17:26 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stdio.h>

typedef struct s_clist
{
	int				number;
	int				index;
	struct s_clist	*next;
	struct s_clist	*prev;
}	t_clist;

typedef struct s_stack
{
	t_clist	*stack;
	int		size;
}	t_stack;

// LST
void	ft_clstadd_back(t_clist **lst, t_clist *new);
t_clist	*ft_clstlast(t_clist *lst);
t_clist	*ft_clstnew(int number, int index);

#endif
