/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_4_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/13 21:44:52 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"

t_bool			push_4_a_to_b(t_var *var, t_shape shape);
static t_bool	normal(t_var *var);
static t_bool	reversed(t_var *var);
static int		get_pivot(t_var *var, t_shape shape);

t_bool	push_4_a_to_b(t_var *var, t_shape shape)
{
	if (shape == NORMAL)
	{
		normal(var);
		if (var->b->tail->prev->val < var->b->tail->val)
			sb(var);
		if (var->a->tail->val < var->a->tail->prev->val)
			sa(var);
	}
	else
	{
		reversed(var);
		if (var->b->tail->val < var->b->tail->prev->val)
			sb(var);
		if (var->a->tail->prev->val < var->a->tail->val)
			sa(var);
	}
	pb(var);
	pb(var);
	return (TRUE);
}

static t_bool	normal(t_var *var)
{
	int	exec_pb;
	int	exec_ra;
	int	pivot;

	exec_pb = 0;
	exec_ra = 0;
	pivot = get_pivot(var, NORMAL);
	while (exec_pb < 2)
	{
		if (pivot <= var->a->tail->val)
		{
			pb(var);
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
	pivot = get_pivot(var, REVERSED);
	while (exec_pb < 2)
	{
		if (var->a->tail->val <= pivot)
		{
			pb(var);
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

static int	get_pivot(t_var *var, t_shape shape)
{
	int		arr[4];
	int		i;
	t_node	*tmp;

	i = 4;
	tmp = var->a->tail;
	while (i--)
	{
		arr[i] = tmp->val;
		tmp = tmp->prev;
	}
	sort_arr(arr, 0, 3);
	if (shape == NORMAL)
		return (arr[2]);
	return (arr[1]);
}
