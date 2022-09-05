/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_3_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/05 17:32:31 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"
#include "../../incs/stack.h"

t_bool	push_3_a_to_b(t_var *var, t_shape shape)
{
	if (shape == NORMAL)
	{
		if (var->a->tail->val < var->a->tail->prev->val)
			sa(var->a);
		push_b(var->a, var->b);
		if (var->a->tail->val < var->a->tail->prev->val)
			sa(var->a);
		push_b(var->a, var->b);
		if (var->b->tail->prev->val < var->b->tail->val)
			sb(var->b);
		push_b(var->a, var->b);
		return (TRUE);
	}
	if (var->a->tail->prev->val < var->a->tail->val)
		sa(var->a);
	push_b(var->a, var->b);
	if (var->a->tail->prev->val < var->a->tail->val)
		sa(var->a);
	push_b(var->a, var->b);
	if (var->b->tail->val < var->b->tail->prev->val)
		sb(var->b);
	push_b(var->a, var->b);
	return (TRUE);
}
