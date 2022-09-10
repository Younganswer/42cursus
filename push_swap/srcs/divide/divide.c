/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:58:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/11 01:03:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"
#include "../../incs/stack.h"

static t_bool	divide_in_triangles(t_var *var);
static t_bool	divide_in_a(t_var *var);
static t_bool	divide_in_b(t_var *var);

t_bool	divide(t_var *var)
{
	set_triangles(var);
	divide_in_triangles(var);
	return (TRUE);
}

static t_bool	divide_in_triangles(t_var *var)
{
	var->a_to_b ^= 1;
	if (var->a_to_b)
	{
		divide_in_b(var);
		var->a_to_b = FALSE;
	}
	else
	{
		while (var->a->sz_)
			pb(var->a, var->b);
		divide_in_a(var);
		var->a_to_b = TRUE;
	}
	return (TRUE);
}

static t_bool	divide_in_a(t_var *var)
{
	t_node	*tmp;

	tmp = var->size_of_triangles_in_a->head;
	while (tmp)
	{
		if (tmp->val == 2)
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
		if (tmp->val == 2)
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
