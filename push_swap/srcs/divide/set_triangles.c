/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_triangles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:00:06 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/13 23:47:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"

t_bool			set_triangles(t_var *var);
static t_bool	make_triangle_in_a(t_var *var);
static t_bool	make_triangle_in_b(t_var *var);
static t_bool	set_size_of_triangles_in_a(t_var *var);
static t_bool	set_size_of_triangles_in_b(t_var *var);

t_bool	set_triangles(t_var *var)
{
	while ((var->a_to_b && var->size_of_triangles_in_a->sz_ < var->divide_in) \
		|| (!var->a_to_b && var->size_of_triangles_in_b->sz_ < var->divide_in))
	{
		if (var->a_to_b)
			make_triangle_in_b(var);
		else
			make_triangle_in_a(var);
		var->a_to_b ^= 1;
	}
	if (var->a_to_b)
		set_size_of_triangles_in_a(var);
	else
		set_size_of_triangles_in_b(var);
	return (TRUE);
}

static t_bool	make_triangle_in_a(t_var *var)
{
	t_node	*to_insert;
	int		size;
	t_shape	shape;
	int		i;

	i = -1;
	while (++i < 2)
	{
		to_insert = var->size_of_triangles_in_b->tail;
		while (to_insert)
		{
			size = to_insert->val;
			shape = to_insert->shape ^ 1;
			push_back(var->size_of_triangles_in_a, init_node(size, shape, 0));
			to_insert = to_insert->prev;
		}
	}
	while (var->size_of_triangles_in_b->sz_)
		push_front(var->size_of_triangles_in_a,
			pop_back(var->size_of_triangles_in_b));
	return (TRUE);
}

static t_bool	make_triangle_in_b(t_var *var)
{
	t_node	*to_insert;
	int		size;
	t_shape	shape;
	int		i;

	i = -1;
	while (++i < 2)
	{
		to_insert = var->size_of_triangles_in_a->tail;
		while (to_insert)
		{
			size = to_insert->val;
			shape = to_insert->shape ^ 1;
			push_back(var->size_of_triangles_in_b, init_node(size, shape, 0));
			to_insert = to_insert->prev;
		}
	}
	while (var->size_of_triangles_in_a->sz_)
		push_front(var->size_of_triangles_in_b,
			pop_back(var->size_of_triangles_in_a));
	return (TRUE);
}

static t_bool	set_size_of_triangles_in_a(t_var *var)
{
	t_node	*tmp;
	int		size;

	tmp = var->size_of_triangles_in_a->head;
	while (tmp)
	{
		tmp->val = 0;
		tmp = tmp->next;
	}
	tmp = var->size_of_triangles_in_a->head;
	size = var->a->sz_;
	while (size--)
	{
		tmp->val++;
		tmp = tmp->next;
		if (!tmp)
			tmp = var->size_of_triangles_in_a->head;
	}
	return (TRUE);
}

static t_bool	set_size_of_triangles_in_b(t_var *var)
{
	t_node	*tmp;
	int		size;

	tmp = var->size_of_triangles_in_b->head;
	while (tmp)
	{
		tmp->val = 0;
		tmp = tmp->next;
	}
	tmp = var->size_of_triangles_in_b->head;
	size = var->a->sz_;
	while (size--)
	{
		tmp->val++;
		tmp = tmp->next;
		if (!tmp)
			tmp = var->size_of_triangles_in_b->head;
	}
	return (TRUE);
}
