/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:58:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/11 23:02:07 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"
#include "../../incs/stack.h"

static t_bool	cal_triangles_num(t_var *var);
static t_bool	divide_in_triangles(t_var *var);
static t_bool	divide_in_a(t_var *var);
static t_bool	divide_in_b(t_var *var);

t_bool	divide(t_var *var)
{
	cal_triangles_num(var);
	set_triangles(var);
	divide_in_triangles(var);
	return (TRUE);
}

static t_bool	cal_triangles_num(t_var *var)
{
	size_t	num;

	var->divide_in = 1;
	num = 5;
	while (num < var->a->sz_)
	{
		num *= 3;
		var->divide_in *= 3;
	}
	return (TRUE);
}

static t_bool	divide_in_triangles(t_var *var)
{
	if (var->a_to_b)
	{
		while (var->a->sz_)
			pb(var->a, var->b);
		divide_in_a(var);
	}
	else
		divide_in_b(var);
	return (TRUE);
}

static t_bool	divide_in_a(t_var *var)
{
	t_node	*tmp;

	tmp = var->size_of_triangles_in_a->head;
	while (tmp)
	{
		if (tmp->val == 1)
			push_back(var->a, pop_back(var->b));
		else if (tmp->val == 2)
			push_2_b_to_a(var, tmp->shape);
		else if (tmp->val == 3)
			push_3_b_to_a(var, tmp->shape);
		else if (tmp->val == 4)
			push_4_b_to_a(var, tmp->shape);
		else if (tmp->val == 5)
			push_5_b_to_a(var, tmp->shape);
		tmp = tmp->next;
	}
	return (TRUE);
}

static t_bool	divide_in_b(t_var *var)
{
	t_node	*tmp;

	tmp = var->size_of_triangles_in_b->head;
	while (tmp)
	{
		if (tmp->val == 1)
			push_back(var->b, pop_back(var->a));
		else if (tmp->val == 2)
			push_2_a_to_b(var, tmp->shape);
		else if (tmp->val == 3)
			push_3_a_to_b(var, tmp->shape);
		else if (tmp->val == 4)
			push_4_a_to_b(var, tmp->shape);
		else if (tmp->val == 5)
			push_5_a_to_b(var, tmp->shape);
		tmp = tmp->next;
	}
	return (TRUE);
}
