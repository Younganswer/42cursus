/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:46:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/14 20:13:39 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"
# include "structs.h"

// init_node.c
t_node	*init_node(int num, t_shape shape, t_exec exec);

// init_stack.c
t_stack	*init_stack(void);

// pop.c
t_node	*pop_front(t_stack *st);
t_node	*pop_back(t_stack *st);

// push.c
t_bool	push_front(t_stack *st, t_node *to_insert);
t_bool	push_back(t_stack *st, t_node *to_insert);

// push_ab.c
t_bool	pa(t_var *var);
t_bool	pb(t_var *var);

// rotate.c
t_bool	ra(t_var *var);
t_bool	rb(t_var *var);
t_bool	rr(t_var *var);

// reverse_rotate.c
t_bool	rra(t_var *var);
t_bool	rrb(t_var *var);
t_bool	rrr(t_var *var);

// swap.c
t_bool	sa(t_var *var);
t_bool	sb(t_var *var);
t_bool	ss(t_var *var);

// stack_utils.c
t_bool	free_stack(t_stack *st);
t_bool	print_exec(t_stack *st);
t_bool	is_sorted(t_stack *st);

#endif