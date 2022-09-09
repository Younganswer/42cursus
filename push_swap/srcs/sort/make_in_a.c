/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_in_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:37:33 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/08 23:24:18 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"
#include "../../incs/stack.h"

t_bool			make_in_a(t_var *var, int size, t_shape shape);
static t_bool	from_a_head(t_var *var, int b_head, int b_tail, t_shape shape);
static t_bool	from_b_head(t_var *var, int a_head, int b_tail, t_shape shape);
static t_bool	from_b_tail(t_var *var, int a_head, int b_head, t_shape shape);

t_bool	make_in_a(t_var *var, int size, t_shape shape)
{
	int	a_head;
	int	b_head;
	int	b_tail;

	a_head = size / 3;
	b_head = size / 3;
	b_tail = size - 2 * (size / 3);
	while (a_head || b_head || b_tail)
	{
		if (a_head && from_a_head(var, b_head, b_tail, shape))
			a_head--;
		else if (b_head && from_b_head(var, a_head, b_tail, shape))
			b_head--;
		else if (b_tail && from_b_tail(var, a_head, b_head, shape))
			b_tail--;
	}
	return (TRUE);
}

static t_bool	from_a_head(t_var *var, int b_head, int b_tail, t_shape shape)
{
	if (shape == NORMAL && b_head && var->a->head->val < var->b->head->val)
		return (FALSE);
	if (shape == NORMAL && b_tail && var->a->head->val < var->b->tail->val)
		return (FALSE);
	if (shape == REVERSED && b_head && var->b->head->val < var->a->head->val)
		return (FALSE);
	if (shape == REVERSED && b_tail && var->b->tail->val < var->a->head->val)
		return (FALSE);
	rra(var->a);
	return (TRUE);
}

static t_bool	from_b_head(t_var *var, int a_head, int b_tail, t_shape shape)
{
	if (shape == NORMAL && a_head && var->b->head->val < var->a->head->val)
		return (FALSE);
	if (shape == NORMAL && b_tail && var->b->head->val < var->b->tail->val)
		return (FALSE);
	if (shape == REVERSED && a_head && var->a->head->val < var->b->head->val)
		return (FALSE);
	if (shape == REVERSED && b_tail && var->b->tail->val < var->b->head->val)
		return (FALSE);
	rrb(var->b);
	pa(var->a, var->b);
	return (TRUE);
}

static t_bool	from_b_tail(t_var *var, int a_head, int b_head, t_shape shape)
{
	if (shape == NORMAL && a_head && var->b->tail->val < var->a->head->val)
		return (FALSE);
	if (shape == NORMAL && b_head && var->b->tail->val < var->b->head->val)
		return (FALSE);
	if (shape == REVERSED && a_head && var->a->head->val < var->b->tail->val)
		return (FALSE);
	if (shape == REVERSED && b_head && var->b->head->val < var->b->tail->val)
		return (FALSE);
	pa(var->a, var->b);
	return (TRUE);
}
