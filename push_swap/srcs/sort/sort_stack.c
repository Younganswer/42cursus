/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:46:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/07 20:00:00 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"

t_bool			sort_stack(t_var *var);
// static t_bool	is_not_sorted(t_stack *a);
// static t_bool	merge(t_var *var, int size, t_shape shape);
// static t_bool	b_to_a(t_var *var, int size);

t_bool	sort_stack(t_var *var)
{
	int	first;
	int	second;
	int	third;

	first = var->a->sz_ - 2 * (var->a->sz_ / 3);
	second = third = var->a->sz_ / 3;
	divide(var, first, NORMAL);
	divide(var, second, REVERSED);
	divide(var, third, REVERSED);
	// merge(var, var->a->sz_ - 2 * (var->a->sz_ / 3), NORMAL);
	// merge(var, var->a->sz_ / 3, REVERSED);
	// merge(var, var->a->sz_ / 3, REVERSED);
	return (TRUE);
}

// static t_bool	b_to_a(t_var *var, int size)
// {
// 	(void) var;
// 	(void) size;
// 	return (TRUE);
// }
