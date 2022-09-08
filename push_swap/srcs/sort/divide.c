/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:36:05 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/08 15:26:52 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"

t_bool			divide(t_var *var, int size, t_shape shape);
static t_bool	a_to_b(t_var *var, int size, t_shape shape);

t_bool	divide(t_var *var, int size, t_shape shape)
{
	int	first;
	int	second;
	int	third;

	second = size - 2 * (size / 3);
	first = third = size / 3;
	if (size < 6)
		a_to_b(var, size, shape);
	else
	{
		if (shape == NORMAL)
		{
			divide(var, first, shape);
			divide(var, second, shape ^ 1);
			divide(var, third, shape ^ 1);
		}
		else
		{
			divide(var, first, shape ^ 1);
			divide(var, second, shape ^ 1);
			divide(var, third, shape);
		}
	}
	return (TRUE);
}

static t_bool	a_to_b(t_var *var, int size, t_shape shape)
{
	ft_printf("size: %d", size);
	(shape == NORMAL) ? ft_printf(", shape: NORMAL\n") : ft_printf(", shape: REVERSE\n");
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
