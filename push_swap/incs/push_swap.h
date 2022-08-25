/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:27:00 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/25 22:36:38 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"

typedef struct s_node
{
	int	val;
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

// push.c
t_bool	push_a(t_stack *a, t_stack *b);
t_bool	push_b(t_stack *a, t_stack *b);

// rotate.c
t_bool	ra(t_stack *a);
t_bool	rb(t_stack *b);
t_bool	rra(t_stack *a);
t_bool	rrb(t_stack *b);

// stack_utils.c
int		pop_front(t_stack *st);
t_bool	push_front(t_stack *st, int num);
int		pop_back(t_stack *st);
t_bool	push_back(t_stack *st, int num);
t_bool	free_stack(t_stack *st);

// swap.c
t_bool	swap(t_stack *st);

#endif