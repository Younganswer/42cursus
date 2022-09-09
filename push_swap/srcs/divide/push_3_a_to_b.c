/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_3_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 21:10:59 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"
#include "../../incs/stack.h"

static t_bool	normal(t_var *var);
static t_bool	reversed(t_var *var);

t_bool	push_3_a_to_b(t_var *var, t_shape shape)
{
	if (shape == NORMAL)
		normal(var);
	else
		reversed(var);
	return (TRUE);
}

static t_bool	normal(t_var *var)
{
	if (var->a->tail->val < var->a->tail->prev->val)
		sa(var->a);
	pb(var->a, var->b);
	if (var->a->tail->val < var->a->tail->prev->val)
		sa(var->a);
	pb(var->a, var->b);
	if (var->b->tail->prev->val < var->b->tail->val)
		sb(var->b);
	pb(var->a, var->b);
	return (TRUE);
	return (TRUE);
}

static t_bool	reversed(t_var *var)
{
	if (var->a->tail->prev->val < var->a->tail->val)
		sa(var->a);
	pb(var->a, var->b);
	if (var->a->tail->prev->val < var->a->tail->val)
		sa(var->a);
	pb(var->a, var->b);
	if (var->b->tail->val < var->b->tail->prev->val)
		sb(var->b);
	pb(var->a, var->b);
	return (TRUE);
}
