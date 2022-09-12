/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_3_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:15:27 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"

t_bool			push_3_a_to_b(t_var *var, t_shape shape);
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
		sa(var);
	pb(var);
	if (var->a->tail->val < var->a->tail->prev->val)
		sa(var);
	pb(var);
	if (var->b->tail->prev->val < var->b->tail->val)
		sb(var);
	pb(var);
	return (TRUE);
}

static t_bool	reversed(t_var *var)
{
	if (var->a->tail->prev->val < var->a->tail->val)
		sa(var);
	pb(var);
	if (var->a->tail->prev->val < var->a->tail->val)
		sa(var);
	pb(var);
	if (var->b->tail->val < var->b->tail->prev->val)
		sb(var);
	pb(var);
	return (TRUE);
}
