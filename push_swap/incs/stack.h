/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:46:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 20:00:18 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"
# include "structs.h"

// init_node.c
t_node	*init_node(int num);

// init_stack.c
t_stack	*init_stack(void);

// pop.c
int		pop_front(t_stack *st);
int		pop_back(t_stack *st);

// push.c
t_bool	push_front(t_stack *st, int num);
t_bool	push_back(t_stack *st, int num);

// push_ab.c
t_bool	push_a(t_stack *a, t_stack *b);
t_bool	push_b(t_stack *a, t_stack *b);

// rotate.c
t_bool	ra(t_stack *a);
t_bool	rb(t_stack *b);
t_bool	rr(t_stack *a, t_stack *b);

// reverse_rotate.c
t_bool	rra(t_stack *a);
t_bool	rrb(t_stack *a);
t_bool	rrr(t_stack *a, t_stack*b);

// swap.c
t_bool	sa(t_stack *a);
t_bool	sb(t_stack *b);
t_bool	ss(t_stack *a, t_stack *b);

// stack_utils.c
t_bool	free_stack(t_stack *st);
t_bool	print_stack(t_stack *st);

#endif