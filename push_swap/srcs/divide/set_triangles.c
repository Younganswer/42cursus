/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_triangles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:00:06 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 22:06:59 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"
#include "../../incs/stack.h"

t_bool			set_triangles(t_var *var);
static t_bool	make_triangle_in_a(t_var *var);
static t_bool	make_triangle_in_b(t_var *var);

t_bool	set_triangles(t_var *var)
{
	if (var->a_to_b)
	{
		if (var->size_of_triangles_in_a->tail->val < 6)
			return (TRUE);
		make_triangle_in_b(var);
	}
	else
	{
		if (var->size_of_triangles_in_b->tail->val < 6)
			return (TRUE);
		make_triangle_in_a(var);
	}
	return (set_triangles(var));
}

static t_bool	make_triangle_in_a(t_var *var)
{
	t_node	*to_insert;
	int		push_to_a;
	int		size;
	t_shape	shape;

	push_to_a = var->size_of_triangles_in_b->sz_;
	while (push_to_a--)
	{
		to_insert = pop_back(var->size_of_triangles_in_b);
		size = to_insert->val;
		shape = to_insert->shape;
		push_front(var->size_of_triangles_in_a, init_node(size / 3, shape));
		push_back(var->size_of_triangles_in_a, init_node(size / 3, shape ^ 1));
		push_front(var->size_of_triangles_in_b, init_node(size - 2 * (size / 3), shape));
		free(to_insert);
	}
	while (var->size_of_triangles_in_b->sz_)
	{
		to_insert = pop_back(var->size_of_triangles_in_b);
		to_insert->shape ^= 1;
		push_back(var->size_of_triangles_in_a, to_insert);
	}
	var->a_to_b = TRUE;
	return (TRUE);
}

static t_bool	make_triangle_in_b(t_var *var)
{
	t_node	*to_insert;
	int		push_to_b;
	int		size;
	t_shape	shape;

	push_to_b = var->size_of_triangles_in_a->sz_;
	while (push_to_b--)
	{
		to_insert = pop_back(var->size_of_triangles_in_a);
		size = to_insert->val;
		shape = to_insert->shape;
		push_front(var->size_of_triangles_in_b, init_node(size / 3, shape));
		push_back(var->size_of_triangles_in_b, init_node(size / 3, shape ^ 1));
		push_front(var->size_of_triangles_in_a, init_node(size - 2 * (size / 3), shape));
		free(to_insert);
	}
	while (var->size_of_triangles_in_a->sz_)
	{
		to_insert = pop_back(var->size_of_triangles_in_a);
		to_insert->shape ^= 1;
		push_back(var->size_of_triangles_in_b, to_insert);
	}
	var->a_to_b = FALSE;
	return (TRUE);
}
