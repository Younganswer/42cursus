/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:38:23 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/13 22:59:00 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	rra(t_var *var);
t_bool	rrb(t_var *var);

t_bool	rra(t_var *var)
{
	if (var->a->sz_ < 2)
		return (TRUE);
	push_back(var->a, pop_front(var->a));
	if (var->exec_st->sz_ && var->exec_st->tail->exec == RRB)
	{
		free(pop_back(var->exec_st));
		push_back(var->exec_st, init_node(0, 0, RRR));
	}
	else
		push_back(var->exec_st, init_node(0, 0, RRA));
	return (TRUE);
}

t_bool	rrb(t_var *var)
{
	if (var->b->sz_ < 2)
		return (TRUE);
	push_back(var->b, pop_front(var->b));
	if (var->exec_st->sz_ && var->exec_st->tail->exec == RRA)
	{
		free(pop_back(var->exec_st));
		push_back(var->exec_st, init_node(0, 0, RRR));
	}
	else
		push_back(var->exec_st, init_node(0, 0, RRB));
	return (TRUE);
}
