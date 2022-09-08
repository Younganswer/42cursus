/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:01:24 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/08 16:26:35 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"
#include "../../incs/stack.h"

t_bool			merge(t_var *var, int size, t_bool a_to_b);
static t_bool	move_top(t_var *var, t_bool a_to_b);
static t_bool	merge_triangles(t_var *var, int size, t_bool to_a);

t_bool	merge(t_var *var, int size, t_bool a_to_b)
{
	if (a_to_b && 6 <= var->a->sz_ / 3 || !a_to_b && 6 <= var->b->sz_ / 3)
		merge(var, size / 3, a_to_b ^ 1);
	move_top(var, a_to_b);
	merge_triangles(var, size / 3, a_to_b);
	merge_triangles(var, size - 2 * (size / 3), a_to_b);
	merge_triangles(var, size / 3, a_to_b);
	return (TRUE);
}

static t_bool	move_top(t_var *var, t_bool a_to_b)
{
	int	move_sz;

	move_sz = var->a->sz_;
	if (!a_to_b)
		move_sz = var->b->sz_;
	move_sz /= 3;
	while (move_sz--)
	{
		if (a_to_b)
			pb(var->a, var->b);
		else
			pa(var->a, var->b);
	}
	return (TRUE);
}

static t_bool	merge_triangles(t_var *var, int size, t_bool a_to_b)
{
	return (TRUE);
}
