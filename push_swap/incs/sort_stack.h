/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:16:58 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/07 21:43:34 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STACK_H
# define SORT_STACK_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"
# include "structs.h"

typedef enum e_shape
{
	NORMAL = 0,
	REVERSED = 1,
}	t_shape;

// sort_stack.c
t_bool	sort_stack(t_var *var);

// divide.c
t_bool	divide(t_var *var, int size, t_shape shape);

// push_2_a_to_b.c
t_bool	push_2_a_to_b(t_var *var, t_shape shape);

// push_3_a_to_b.c
t_bool	push_3_a_to_b(t_var *var, t_shape shape);

// push_4_a_to_b.c
t_bool	push_4_a_to_b(t_var *var, t_shape shape);

// push_5_a_to_b.c
t_bool	push_5_a_to_b(t_var *var, t_shape shape);

#endif