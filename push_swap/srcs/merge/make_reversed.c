/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_reversed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:48:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/13 23:04:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/merge.h"

t_bool			make_reversed(t_var *var);
static t_bool	make_in_a(t_var *var);
static t_bool	make_in_b(t_var *var);
static t_bool	sort_in_a(t_var *var);
static t_bool	sort_in_b(t_var *var);

t_bool	make_reversed(t_var *var)
{
	if (var->a_to_b)
		make_in_b(var);
	else
		make_in_a(var);
	return (TRUE);
}

static t_bool	make_in_a(t_var *var)
{
	push_back(var->size_of_triangles_in_a,
		init_node(
			var->size_of_triangles_in_a->head->val + \
			var->size_of_triangles_in_b->head->val + \
			var->size_of_triangles_in_b->tail->val,
			REVERSED,
			0
			)
		);
	sort_in_a(var);
	free(pop_front(var->size_of_triangles_in_a));
	free(pop_front(var->size_of_triangles_in_b));
	free(pop_back(var->size_of_triangles_in_b));
	return (TRUE);
}

static t_bool	make_in_b(t_var *var)
{
	push_back(var->size_of_triangles_in_b,
		init_node(
			var->size_of_triangles_in_b->head->val + \
			var->size_of_triangles_in_a->head->val + \
			var->size_of_triangles_in_a->tail->val,
			REVERSED,
			0
			)
		);
	sort_in_b(var);
	free(pop_front(var->size_of_triangles_in_b));
	free(pop_front(var->size_of_triangles_in_a));
	free(pop_back(var->size_of_triangles_in_a));
	return (TRUE);
}

static t_bool	sort_in_a(t_var *var)
{
	while (var->size_of_triangles_in_a->head->val || \
			var->size_of_triangles_in_b->head->val || \
			var->size_of_triangles_in_b->tail->val)
	{
		if (var->size_of_triangles_in_a->head->val && \
			(!var->size_of_triangles_in_b->head->val || \
			var->b->head->val > var->a->head->val) && \
			(!var->size_of_triangles_in_b->tail->val || \
			var->b->tail->val > var->a->head->val) && rra(var))
			var->size_of_triangles_in_a->head->val--;
		else if (var->size_of_triangles_in_b->head->val && \
				(!var->size_of_triangles_in_a->head->val || \
				var->a->head->val > var->b->head->val) && \
				(!var->size_of_triangles_in_b->tail->val || \
				var->b->tail->val > var->b->head->val) && \
				rrb(var) && pa(var))
			var->size_of_triangles_in_b->head->val--;
		else if (var->size_of_triangles_in_b->tail->val && \
			(!var->size_of_triangles_in_a->head->val || \
			var->a->head->val > var->b->tail->val) && \
			(!var->size_of_triangles_in_b->head->val || \
			var->b->head->val > var->b->tail->val) && pa(var))
			var->size_of_triangles_in_b->tail->val--;
	}
	return (TRUE);
}

static t_bool	sort_in_b(t_var *var)
{
	while (var->size_of_triangles_in_b->head->val || \
			var->size_of_triangles_in_a->head->val || \
			var->size_of_triangles_in_a->tail->val)
	{
		if (var->size_of_triangles_in_b->head->val && \
			(!var->size_of_triangles_in_a->head->val || \
			var->a->head->val > var->b->head->val) && \
			(!var->size_of_triangles_in_a->tail->val || \
			var->a->tail->val > var->b->head->val) && rrb(var))
			var->size_of_triangles_in_b->head->val--;
		else if (var->size_of_triangles_in_a->head->val && \
				(!var->size_of_triangles_in_b->head->val || \
				var->b->head->val > var->a->head->val) && \
				(!var->size_of_triangles_in_a->tail->val || \
				var->a->tail->val > var->a->head->val) && \
				rra(var) && pb(var))
			var->size_of_triangles_in_a->head->val--;
		else if (var->size_of_triangles_in_a->tail->val && \
			(!var->size_of_triangles_in_b->head->val || \
			var->b->head->val > var->a->tail->val) && \
			(!var->size_of_triangles_in_a->head->val || \
			var->a->head->val > var->a->tail->val) && pb(var))
			var->size_of_triangles_in_a->tail->val--;
	}
	return (TRUE);
}
