/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:18:05 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/11 16:09:26 by younhwan         ###   ########.fr       */
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

typedef struct s_node
{
	int				val;
	t_shape			shape;
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
	t_bool	a_to_b;
}	t_var;

#endif