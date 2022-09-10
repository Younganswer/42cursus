/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:48:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/11 01:03:35 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/merge.h"
#include "../../incs/stack.h"

t_bool			merge(t_var *var);
static t_bool	move_top(t_var *var);

t_bool	merge(t_var *var)
{
	while (var->size_of_triangles_in_a->sz_ != 1)
	{
		move_top(var);
		while ((var->a_to_b && var->size_of_triangles_in_a->sz_) || \
				(!var->a_to_b && var->size_of_triangles_in_b->sz_))
		{
			if ((var->size_of_triangles_in_a->sz_ && \
			var->size_of_triangles_in_a->head->shape == NORMAL) || \
			(var->size_of_triangles_in_b->sz_ && \
			var->size_of_triangles_in_b->head->shape == NORMAL))
				make_normal(var);
			else
				make_reversed(var);
			ft_printf("\nStack_a\n");
			print_stack(var->a);
			ft_printf("\nStack_b\n");
			print_stack(var->b);
		}
		var->a_to_b ^= 1;
	}
	return (TRUE);
}

static t_bool	move_top(t_var *var)
{
	t_node	*to_move;
	int		size;

	if (var->a_to_b)
	{
		size = var->a->sz_ - 2 * (var->a->sz_ / 3);
		while (size--)
			pb(var->a, var->b);
		size = var->size_of_triangles_in_a->sz_ - \
				2 * (var->size_of_triangles_in_a->sz_ / 3);
		while (size--)
		{
			to_move = pop_back(var->size_of_triangles_in_a);
			to_move->shape ^= 1;
			push_back(var->size_of_triangles_in_b, to_move);
		}
		return (TRUE);
	}
	size = var->b->sz_ - 2 * (var->b->sz_ / 3);
	while (size--)
		pa(var->a, var->b);
	size = var->size_of_triangles_in_b->sz_ - \
			2 * (var->size_of_triangles_in_b->sz_ / 3);
	while (size--)
	{
		to_move = pop_back(var->size_of_triangles_in_b);
		to_move->shape ^= 1;
		push_back(var->size_of_triangles_in_a, to_move);
	}
	return (TRUE);
}
