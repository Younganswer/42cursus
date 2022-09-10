/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_4_b_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/11 01:01:10 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"
#include "../../incs/parse_input.h"
#include "../../incs/stack.h"

t_bool			push_4_b_to_a(t_var *var, t_shape shape);
static t_bool	normal(t_var *var);
static t_bool	reversed(t_var *var);
static int		get_pivot(t_var *var, t_shape shape);

t_bool	push_4_b_to_a(t_var *var, t_shape shape)
{
	if (shape == NORMAL)
	{
		normal(var);
		if (var->a->tail->prev->val < var->a->tail->val && \
			var->b->tail->val < var->b->tail->prev->val)
			ss(var->a, var->b);
		else if (var->a->tail->prev->val < var->a->tail->val)
			sa(var->a);
		else if (var->b->tail->val < var->b->tail->prev->val)
			sb(var->b);
	}
	else
	{
		reversed(var);
		if (var->a->tail->val < var->a->tail->prev->val && \
			var->b->tail->prev->val < var->b->tail->val)
			ss(var->a, var->b);
		else if (var->a->tail->val < var->a->tail->prev->val)
			sa(var->a);
		else if (var->b->tail->prev->val < var->b->tail->val)
			sb(var->b);
	}
	pa(var->a, var->b);
	pa(var->a, var->b);
	return (TRUE);
}

static t_bool	normal(t_var *var)
{
	int	exec_pa;
	int	exec_rb;
	int	pivot;

	exec_pa = 0;
	exec_rb = 0;
	pivot = get_pivot(var, NORMAL);
	while (exec_pa < 2)
	{
		if (pivot <= var->b->tail->val)
		{
			pa(var->a, var->b);
			exec_pa++;
		}
		else
		{
			rb(var->b);
			exec_rb++;
		}
	}
	while (exec_rb--)
		rrb(var->b);
	return (TRUE);
}

static t_bool	reversed(t_var *var)
{
	int	exec_pa;
	int	exec_rb;
	int	pivot;

	exec_pa = 0;
	exec_rb = 0;
	pivot = get_pivot(var, REVERSED);
	while (exec_pa < 2)
	{
		if (var->b->tail->val <= pivot)
		{
			pa(var->a, var->b);
			exec_pa++;
		}
		else
		{
			rb(var->b);
			exec_rb++;
		}
	}
	while (exec_rb--)
		rrb(var->b);
	return (TRUE);
}

static int	get_pivot(t_var *var, t_shape shape)
{
	int		arr[4];
	int		i;
	t_node	*tmp;

	i = 4;
	tmp = var->b->tail;
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
