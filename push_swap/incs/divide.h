/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:57:14 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/05 21:25:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIVIDE_H
# define DIVIDE_H

# include "../libs/ft_printf/libft/incs/libft.h"
# include "structs.h"
# include "stack.h"
# include "parse_input.h"

// divide.c
t_bool	divide(t_var *var);

// push_2_a_to_b.c
t_bool	push_2_a_to_b(t_var *var, t_shape shape);

// push_3_a_to_b.c
t_bool	push_3_a_to_b(t_var *var, t_shape shape);

// push_4_a_to_b.c
t_bool	push_4_a_to_b(t_var *var, t_shape shape);

// push_5_a_to_b.c
t_bool	push_5_a_to_b(t_var *var, t_shape shape);

// push_2_b_to_a.c
t_bool	push_2_b_to_a(t_var *var, t_shape shape);

// push_3_b_to_a.c
t_bool	push_3_b_to_a(t_var *var, t_shape shape);

// push_4_b_to_a.c
t_bool	push_4_b_to_a(t_var *var, t_shape shape);

// push_5_b_to_a.c
t_bool	push_5_b_to_a(t_var *var, t_shape shape);

// set_triangles.c
t_bool	set_triangles(t_var *var);

#endif