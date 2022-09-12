/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:48:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:18:55 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/merge.h"

t_bool			merge(t_var *var);
static t_bool	move_a_top_to_b(t_var *var);
static t_bool	move_b_top_to_a(t_var *var);

t_bool	merge(t_var *var)
{
	while (var->size_of_triangles_in_a->sz_ != 1)
	{
		if (var->a_to_b)
			move_a_top_to_b(var);
		else
			move_b_top_to_a(var);
		while ((var->a_to_b && var->size_of_triangles_in_a->sz_) || \
				(!var->a_to_b && var->size_of_triangles_in_b->sz_))
		{
			if ((var->a_to_b && \
				var->size_of_triangles_in_a->tail->shape == REVERSED) || \
				(!var->a_to_b && \
				var->size_of_triangles_in_b->tail->shape == REVERSED))
				make_normal(var);
			else
				make_reversed(var);
		}
		var->a_to_b ^= 1;
	}
	return (TRUE);
}

static t_bool	move_a_top_to_b(t_var *var)
{
	t_node	*to_move;
	int		num_of_triangles;
	int		size;
	t_bool	flag;

	flag = var->size_of_triangles_in_b->sz_;
	num_of_triangles = var->size_of_triangles_in_a->sz_ - \
			2 * (var->size_of_triangles_in_a->sz_ / 3);
	size = 0;
	while (num_of_triangles--)
	{
		to_move = pop_back(var->size_of_triangles_in_a);
		to_move->shape ^= 1;
		size += to_move->val;
		if (flag)
			push_front(var->size_of_triangles_in_b, to_move);
		else
			push_back(var->size_of_triangles_in_b, to_move);
	}
	if (flag)
		sa(var);
	while (size--)
		if (pb(var) && flag)
			rb(var);
	return (TRUE);
}

static t_bool	move_b_top_to_a(t_var *var)
{
	t_node	*to_move;
	int		num_of_triangles;
	int		size;
	t_bool	flag;

	flag = var->size_of_triangles_in_a->sz_;
	num_of_triangles = var->size_of_triangles_in_b->sz_ - \
			2 * (var->size_of_triangles_in_b->sz_ / 3);
	size = 0;
	while (num_of_triangles--)
	{
		to_move = pop_back(var->size_of_triangles_in_b);
		to_move->shape ^= 1;
		size += to_move->val;
		if (flag)
			push_front(var->size_of_triangles_in_a, to_move);
		else
			push_back(var->size_of_triangles_in_a, to_move);
	}
	if (flag)
		sb(var);
	while (size--)
		if (pa(var) && flag)
			ra(var);
	return (TRUE);
}
