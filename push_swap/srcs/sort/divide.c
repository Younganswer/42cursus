/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:36:05 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/07 19:38:29 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"

t_bool			divide(t_var *var, int size, t_shape shape);
static t_bool	a_to_b(t_var *var, int size, t_shape shape);

t_bool	divide(t_var *var, int size, t_shape shape)
{
	if (size < 5)
		a_to_b(var, size, shape);
	else
	{
		divide(var, size - 2 * (size / 3), shape);
		divide(var, size / 3, shape ^ 1);
		divide(var, size / 3, shape ^ 1);
	}
	return (TRUE);
}

static t_bool	a_to_b(t_var *var, int size, t_shape shape)
{
	if (size == 2)
		push_2_a_to_b(var, shape);
	else if (size == 3)
		push_3_a_to_b(var, shape);
	else if (size == 4)
		push_4_a_to_b(var, shape);
	else if (size == 5)
		push_5_a_to_b(var, shape);
	return (TRUE);
}
