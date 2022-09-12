/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_5_b_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:18:26 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"

t_bool			push_5_b_to_a(t_var *var, t_shape shape);
static t_bool	normal(t_var *var);
static t_bool	reversed(t_var *var);
static int		get_pivot(t_var *var);

t_bool	push_5_b_to_a(t_var *var, t_shape shape)
{
	if (shape == NORMAL)
		normal(var);
	else
		reversed(var);
	push_3_b_to_a(var, shape);
	rra(var);
	rra(var);
	if ((shape == NORMAL && var->a->tail->prev->val < var->a->tail->val) || \
		(shape == REVERSED && var->a->tail->val < var->a->tail->prev->val))
		sa(var);
	return (TRUE);
}

static t_bool	normal(t_var *var)
{
	int	exec_pa;
	int	exec_rb;
	int	pivot;

	exec_pa = 0;
	exec_rb = 0;
	pivot = get_pivot(var);
	while (exec_pa < 2)
	{
		if (var->b->tail->val < pivot)
		{
			pa(var);
			ra(var);
			exec_pa++;
		}
		else
		{
			rb(var);
			exec_rb++;
		}
	}
	while (exec_rb--)
		rrb(var);
	return (TRUE);
}

static t_bool	reversed(t_var *var)
{
	int	exec_pa;
	int	exec_rb;
	int	pivot;

	exec_pa = 0;
	exec_rb = 0;
	pivot = get_pivot(var);
	while (exec_pa < 2)
	{
		if (pivot < var->b->tail->val)
		{
			pa(var);
			ra(var);
			exec_pa++;
		}
		else
		{
			rb(var);
			exec_rb++;
		}
	}
	while (exec_rb--)
		rrb(var);
	return (TRUE);
}

static int	get_pivot(t_var *var)
{
	int		arr[5];
	int		i;
	t_node	*tmp;

	i = 5;
	tmp = var->b->tail;
	while (i--)
	{
		arr[i] = tmp->val;
		tmp = tmp->prev;
	}
	sort_arr(arr, 0, 4);
	return (arr[2]);
}
