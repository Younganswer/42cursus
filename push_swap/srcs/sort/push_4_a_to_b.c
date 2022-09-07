/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_4_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/07 19:38:12 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"
#include "../../incs/stack.h"

t_bool			push_4_a_to_b(t_var *var, t_shape shape);
static t_bool 	normal(t_var *var);
static t_bool 	reversed(t_var *var);
static int		get_min_2(t_var *var);
static int		get_max_2(t_var *var);

t_bool	push_4_a_to_b(t_var *var, t_shape shape)
{
	if (shape == NORMAL)
		normal(var);
	else
		reversed(var);
	return (TRUE);
}

static t_bool	normal(t_var *var)
{
	int	i;
	int	max_2;
	int	exec_ra;

	i = 4;
	max_2 = get_max_2(var);
	exec_ra = 0;
	while (i--)
	{
		if (max_2 <= var->a->tail->val)
			pb(var->a, var->b);
		else
		{
			ra(var->a);
			exec_ra++;
		}
	}
	while (exec_ra--)
		rra(var->a);
	if (var->b->tail->prev->val < var->b->tail->val\
	 && var->a->tail->val < var->a->tail->prev->val)
		ss(var->a, var->b);
	else if (var->b->tail->prev->val < var->b->tail->val)
		sb(var->b);
	else if (var->a->tail->val < var->a->tail->prev->val)
		sa(var->a);
	pb(var->a, var->b);
	pb(var->a, var->b);
	return (TRUE);
}

static t_bool	reversed(t_var *var)
{
	int	i;
	int	min_2;
	int	exec_ra;

	i = 4;
	min_2 = get_min_2(var);
	exec_ra = 0;
	while (i--)
	{
		if (var->a->tail->val <= min_2)
			pb(var->a, var->b);
		else
		{
			ra(var->a);
			exec_ra++;
		}
	}
	while (exec_ra--)
		rra(var->a);
	if (var->b->tail->val < var->b->tail->prev->val\
	 && var->a->tail->prev->val < var->a->tail->val)
		ss(var->a, var->b);
	else if (var->b->tail->val < var->b->tail->prev->val)
		sb(var->b);
	else if (var->a->tail->prev->val < var->a->tail->val)
		sa(var->a);
	pb(var->a, var->b);
	pb(var->a, var->b);
	return (TRUE);
}

static int	get_min_2(t_var *var)
{
	int		min;
	int		min_2;
	int		i;
	t_node	*tmp;

	min = INT32_MAX;
	i = 4;
	tmp = var->a->tail;
	while (i--)
	{
		if (tmp->val < min)
		{
			min_2 = min;
			min = tmp->val;
		}
		tmp = tmp->prev;
	}
	return (min_2);
}

static int	get_max_2(t_var *var)
{
	int		max;
	int		max_2;
	int		i;
	t_node	*tmp;

	max = INT32_MIN;
	i = 4;
	tmp = var->a->tail;
	while (i--)
	{
		if (max < tmp->val)
		{
			max_2 = max;
			max = tmp->val;
		}
		tmp = tmp->prev;
	}
	return (max_2);
}
