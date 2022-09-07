/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_2_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/07 17:12:10 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"
#include "../../incs/stack.h"

t_bool	push_2_a_to_b(t_var *var, t_shape shape)
{
	pb(var->a, var->b);
	pb(var->a, var->b);
	if ((var->b->tail->val < var->b->tail->prev->val && shape == REVERSED) \
		|| (var->b->tail->prev->val < var->b->tail->val && shape == NORMAL))
		sb(var->b);
	return (TRUE);
}
