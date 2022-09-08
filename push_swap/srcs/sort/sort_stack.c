/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:46:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/08 15:27:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"
#include "../../incs/stack.h"

t_bool	sort_stack(t_var *var);
// t_bool	sort_small(t_var *var);
// static t_bool	b_to_a(t_var *var, int size);

t_bool	sort_stack(t_var *var)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(var->a))
		return (TRUE);
	// if (var->a->sz_ < 6)
	// 	return (sort_small(var));
	second = var->a->sz_ - 2 * (var->a->sz_ / 3);
	first = third = var->a->sz_ / 3;
	divide(var, first, NORMAL);
	divide(var, second, REVERSED);
	divide(var, third, REVERSED);
	print_stack(var->b);
	// merge(var, var->b->sz_, FALSE);
	return (TRUE);
}

// static t_bool	b_to_a(t_var *var, int size)
// {
// 	(void) var;
// 	(void) size;
// 	return (TRUE);
// }
