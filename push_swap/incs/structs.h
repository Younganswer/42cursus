/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:18:05 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:00:54 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"

typedef enum e_shape
{
	NORMAL = 0,
	REVERSED = 1
}	t_shape;

typedef enum e_exec
{
	SA = 0,
	SB = 1,
	SS = 2,
	PA = 3,
	PB = 4,
	RA = 5,
	RB = 6,
	RR = 7,
	RRA = 8,
	RRB = 9,
	RRR = 10,
}	t_exec;

typedef struct s_node
{
	int				val;
	t_shape			shape;
	t_exec			exec;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	sz_;
}	t_stack;

typedef struct s_var
{
	t_stack	*a;
	t_stack	*b;
	t_stack *size_of_triangles_in_a;
	t_stack *size_of_triangles_in_b;
	t_stack	*exec_st;
	size_t	divide_in;
	t_bool	a_to_b;
}	t_var;

#endif