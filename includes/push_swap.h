/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:21:21 by lquehec           #+#    #+#             */
/*   Updated: 2023/12/13 20:01:29 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

# define SMALL_SORT_LIMIT	5

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define LONG_MIN -9223372036854775808
# define LONG_MAX 9223372036854775807

enum	e_errors
{
	MEMORY_ERR			= -1,
	ARGS_ERR			= -2,
	SORT_ERR			= -3,
	CMD_ERR				= -4,
	EMPTY_ERR			= -999,
};

typedef struct s_number
{
	int	value;
	int	index;
}	t_number;

typedef struct s_clist
{
	int				number;
	int				current_index;
	int				operation_cost;
	int				cheapest;
	int				above_median;
	struct s_clist	*target_node;
	struct s_clist	*next;
	struct s_clist	*prev;
}	t_clist;

typedef struct s_stack
{
	t_clist	*stack;
	int		size;
}	t_stack;

// LST
void		ft_clstadd_back(t_clist **lst, t_clist *new);
void		ft_clstadd_front(t_clist **lst, t_clist *new);
void		ft_clstdelfirst(t_clist **head);
void		ft_clstfree(t_clist **head);
void		ft_clstfree_node(t_clist *node);
t_clist		*ft_clstlast(t_clist *lst);
t_clist		*ft_clstnew(int number);

// SORTING
void		sorting(t_stack *stack_a, t_stack *stack_b);
void		three_sort(t_stack *stack);

// SORTING COMPLEX
void		complex_sort(t_stack *stack_a, t_stack *stack_b);

// SORTING INIT
void		init_sort(t_stack *stack_a, t_stack *stack_b);

// SORTING UTILS
t_clist		*find_smallest_node(t_stack *stack);
t_number	ft_find_smallest(t_stack *stack);
t_clist		*get_cheapest(t_stack *stack);
void		set_current_index(t_stack *stack);

// PRINT
void		ft_print_stacks(t_stack *stack_a, t_stack *stack_b);
void		ft_print_clst(t_clist **head, char *name);
void		ft_print_allnodes(t_clist **head, char *name);

// INIT
void		ft_init_stack(t_stack *stack);

// PARSING
void		parsing(t_stack *stack_a, int ac, char **av);

// EXIT
void		*ft_exit(t_stack *stack_a, \
					t_stack *stack_b, \
					int error, \
					char *param);

// ERROR
void		ft_error(int error, char *param);

// IS
int			is_int(int num);
int			is_whitespace(char c);
int			is_in_range(int a, int b, int c);
int			is_sorted(t_clist **head);

// UTILS
long		ft_atol(const char *str);

// FREE
void		ft_free_matrix_with_indice(char **matrix, int i);
void		ft_free_matrix(char **matrix);

/* ========== MOVES ==========*/
// SWAP
void		ft_swap(t_stack *stack);
void		sa(t_stack *stack_a, int print);
void		sb(t_stack *stack_b, int print);
void		ss(t_stack *stack_a, t_stack *stack_b, int print);

// ROTATE
void		ft_rotate(t_stack *stack);
void		ra(t_stack *stack_a, int print);
void		rb(t_stack *stack_b, int print);
void		rr(t_stack *stack_a, t_stack *stack_b, int print);

// REVERSE ROTATE
void		ft_rrotate(t_stack *stack);
void		rra(t_stack *stack_a, int print);
void		rrb(t_stack *stack_b, int print);
void		rrr(t_stack *stack_a, t_stack *stack_b, int print);

// PUSH
void		ft_push(t_stack *stack_src, t_stack *stack_dest);
void		pa(t_stack *stack_a, t_stack *stack_b, int print);
void		pb(t_stack *stack_a, t_stack *stack_b, int print);
/* ========== MOVES ==========*/

#endif
