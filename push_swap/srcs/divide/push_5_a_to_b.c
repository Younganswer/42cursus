/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_5_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:18:01 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"

t_bool			push_5_a_to_b(t_var *var, t_shape shape);
static t_bool	normal(t_var *var);
static t_bool	reversed(t_var *var);
static int		get_pivot(t_var *var);

t_bool	push_5_a_to_b(t_var *var, t_shape shape)
{
	if (shape == NORMAL)
		normal(var);
	else
		reversed(var);
	push_3_a_to_b(var, shape);
	rrb(var);
	rrb(var);
	if ((shape == NORMAL && var->b->tail->prev->val < var->b->tail->val) || \
		(shape == REVERSED && var->b->tail->val < var->b->tail->prev->val))
		sb(var);
	return (TRUE);
}

static t_bool	normal(t_var *var)
{
	int	exec_pb;
	int	exec_ra;
	int	pivot;

	exec_pb = 0;
	exec_ra = 0;
	pivot = get_pivot(var);
	while (exec_pb < 2)
	{
		if (var->a->tail->val < pivot)
		{
			pb(var);
			rb(var);
			exec_pb++;
		}
		else
		{
			ra(var);
			exec_ra++;
		}
	}
	while (exec_ra--)
		rra(var);
	return (TRUE);
}

static t_bool	reversed(t_var *var)
{
	int	exec_pb;
	int	exec_ra;
	int	pivot;

	exec_pb = 0;
	exec_ra = 0;
	pivot = get_pivot(var);
	while (exec_pb < 2)
	{
		if (pivot < var->a->tail->val)
		{
			pb(var);
			rb(var);
			exec_pb++;
		}
		else
		{
			ra(var);
			exec_ra++;
		}
	}
	while (exec_ra--)
		rra(var);
	return (TRUE);
}

static int	get_pivot(t_var *var)
{
	int		arr[5];
	int		i;
	t_node	*tmp;

	i = 5;
	tmp = var->a->tail;
	while (i--)
	{
		arr[i] = tmp->val;
		tmp = tmp->prev;
	}
	sort_arr(arr, 0, 4);
	return (arr[2]);
}
