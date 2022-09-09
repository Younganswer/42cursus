/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:37:33 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/08 23:27:19 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"
#include "../../incs/stack.h"

t_bool			make_in_a(t_var *var, int size, t_shape shape);
static t_bool	from_b_head(t_var *var, int a_head, int a_tail, t_shape shape);
static t_bool	from_a_head(t_var *var, int b_head, int a_tail, t_shape shape);
static t_bool	from_a_tail(t_var *var, int b_head, int a_head, t_shape shape);

t_bool	make_in_b(t_var *var, int size, t_shape shape)
{
	int	b_head;
	int	a_head;
	int	a_tail;

	b_head = size / 3;
	a_head = size / 3;
	a_tail = size - 2 * (size / 3);
	while (b_head || a_head || a_tail)
	{
		if (b_head && from_b_head(var, a_head, a_tail, shape))
			b_head--;
		else if (a_head && from_a_head(var, b_head, a_tail, shape))
			a_head--;
		else if (a_tail && from_a_tail(var, b_head, a_head, shape))
			a_tail--;
	}
	return (TRUE);
}

static t_bool	from_b_head(t_var *var, int a_head, int a_tail, t_shape shape)
{
	if (shape == NORMAL && a_head && var->b->head->val < var->a->head->val)
		return (FALSE);
	if (shape == NORMAL && a_tail && var->b->head->val < var->a->tail->val)
		return (FALSE);
	if (shape == REVERSED && a_head && var->a->head->val < var->b->head->val)
		return (FALSE);
	if (shape == REVERSED && a_tail && var->a->tail->val < var->b->head->val)
		return (FALSE);
	rrb(var->b);
	return (TRUE);
}

static t_bool	from_a_head(t_var *var, int b_head, int a_tail, t_shape shape)
{
	if (shape == NORMAL && b_head && var->a->head->val < var->b->head->val)
		return (FALSE);
	if (shape == NORMAL && a_tail && var->a->head->val < var->a->tail->val)
		return (FALSE);
	if (shape == REVERSED && b_head && var->b->head->val < var->a->head->val)
		return (FALSE);
	if (shape == REVERSED && a_tail && var->a->tail->val < var->a->head->val)
		return (FALSE);
	rra(var->a);
	pb(var->a, var->b);
	return (TRUE);
}

static t_bool	from_a_tail(t_var *var, int b_head, int a_head, t_shape shape)
{
	if (shape == NORMAL && b_head && var->a->tail->val < var->b->head->val)
		return (FALSE);
	if (shape == NORMAL && a_head && var->a->tail->val < var->a->head->val)
		return (FALSE);
	if (shape == REVERSED && b_head && var->b->head->val < var->a->tail->val)
		return (FALSE);
	if (shape == REVERSED && a_head && var->a->head->val < var->a->tail->val)
		return (FALSE);
	pb(var->a, var->b);
	return (TRUE);
}
