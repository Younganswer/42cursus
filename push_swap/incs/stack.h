/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:46:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/01 00:03:36 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	sz_;
}	t_stack;

// init_node.c
t_node	*init_node(int num);

// init_stack.c
t_stack	*init_stack(void);

// push_ab.c
t_bool	push_a(t_stack *a, t_stack *b);
t_bool	push_b(t_stack *a, t_stack *b);

// rotate.c
t_bool	rotate(t_stack *st);
t_bool	reverse_rotate(t_stack *st);

// stack_utils.c
t_bool	free_stack(t_stack *st);
t_bool	print_stack(t_stack *st);

// pop.c
int		pop_front(t_stack *st);
int		pop_back(t_stack *st);

// push.c
t_bool	push_front(t_stack *st, int num);
t_bool	push_back(t_stack *st, int num);

// swap.c
t_bool	swap(t_stack *st);

#endif