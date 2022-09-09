/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size_of_triangles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:00:06 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 19:03:56 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"
#include "../../incs/stack.h"

t_bool			set_size_of_triangles(t_var *var);
static t_bool	make_triangle_in_a(t_var *var);
static t_bool	make_triangle_in_b(t_var *var);

t_bool	set_size_of_triangles(t_var *var)
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
	return (set_size_of_triangles(var));
}

static t_bool	make_triangle_in_a(t_var *var)
{
	int	push_to_a;
	int	size;

	push_to_a = var->size_of_triangles_in_b->sz_;
	while (push_to_a--)
	{
		size = pop_back(var->b);
		push_front(var->a, size / 3);
		push_back(var->a, size / 3);
		push_front(var->b, size - 2 * (size / 3));
	}
	while (var->b->sz_)
		push_back(var->a, pop_back(var->b));
	var->a_to_b = FALSE;
	return (TRUE);
}

static t_bool	make_triangle_in_b(t_var *var)
{
	int	push_to_b;
	int	size;

	push_to_b = var->size_of_triangles_in_a->sz_;
	while (push_to_b--)
	{
		size = pop_back(var->a);
		push_front(var->b, size / 3);
		push_back(var->b, size / 3);
		push_front(var->a, size - 2 * (size / 3));
	}
	while (var->a->sz_)
		push_back(var->b, pop_back(var->a));
	var->a_to_b = TRUE;
	return (TRUE);
}
