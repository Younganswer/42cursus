/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_4_a_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/07 21:41:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"
#include "../../incs/parse_input.h"
#include "../../incs/stack.h"

t_bool			push_4_a_to_b(t_var *var, t_shape shape);
static t_bool	normal(t_var *var);
static t_bool	reversed(t_var *var);
static int		get_min_2(t_var *var);
static int		get_max_2(t_var *var);

t_bool	push_4_a_to_b(t_var *var, t_shape shape)
{
	if (shape == NORMAL)
	{
		normal(var);
		if (var->b->tail->prev->val < var->b->tail->val && \
			var->a->tail->val < var->a->tail->prev->val)
			ss(var->a, var->b);
		else if (var->b->tail->prev->val < var->b->tail->val)
			sb(var->b);
		else if (var->a->tail->val < var->a->tail->prev->val)
			sa(var->a);
	}
	else
	{
		reversed(var);
		if (var->b->tail->val < var->b->tail->prev->val && \
			var->a->tail->prev->val < var->a->tail->val)
			ss(var->a, var->b);
		else if (var->b->tail->val < var->b->tail->prev->val)
			sb(var->b);
		else if (var->a->tail->prev->val < var->a->tail->val)
			sa(var->a);
	}
	pb(var->a, var->b);
	pb(var->a, var->b);
	return (TRUE);
}

static t_bool	normal(t_var *var)
{
	int	exec_pb;
	int	exec_ra;
	int	max_2;

	exec_pb = 0;
	exec_ra = 0;
	max_2 = get_max_2(var);
	while (exec_pb < 2)
	{
		if (max_2 <= var->a->tail->val)
		{
			pb(var->a, var->b);
			exec_pb++;
		}
		else
		{
			ra(var->a);
			exec_ra++;
		}
	}
	while (exec_ra--)
		rra(var->a);
	return (TRUE);
}

static t_bool	reversed(t_var *var)
{
	int	exec_pb;
	int	exec_ra;
	int	min_2;

	exec_pb = 0;
	exec_ra = 0;
	min_2 = get_min_2(var);
	while (exec_pb < 2)
	{
		if (var->a->tail->val <= min_2)
		{
			pb(var->a, var->b);
			exec_pb++;
		}
		else
		{
			ra(var->a);
			exec_ra++;
		}
	}
	while (exec_ra--)
		rra(var->a);
	return (TRUE);
}

static int	get_min_2(t_var *var)
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
	return (arr[1]);
}

static int	get_max_2(t_var *var)
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
	return (arr[2]);
}
