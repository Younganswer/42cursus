/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:38:23 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:09:42 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	rra(t_var *var);
t_bool	rrb(t_var *var);

t_bool	rra(t_var *var)
{
	t_node	*front;

	if (var->a->sz_ < 2)
		return (TRUE);
	front = pop_front(var->a);
	push_back(var->a, front);
	if (var->exec_st->tail->exec == RRB)
	{
		pop_back(var->exec_st);
		push_back(var->exec_st, init_node(0, 0, RRR));
	}
	else
		push_back(var->exec_st, init_node(0, 0, RRA));
	return (TRUE);
}

t_bool	rrb(t_var *var)
{
	t_node	*front;

	if (var->b->sz_ < 2)
		return (TRUE);
	front = pop_front(var->b);
	push_back(var->b, front);
	if (var->exec_st->tail->exec == RRA)
	{
		pop_back(var->exec_st);
		push_back(var->exec_st, init_node(0, 0, RRR));
	}
	else
		push_back(var->exec_st, init_node(0, 0, RRB));
	return (TRUE);
}
