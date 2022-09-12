/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:28:55 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:08:29 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	ra(t_var *var);
t_bool	rb(t_var *var);

t_bool	ra(t_var *var)
{
	t_node	*back;

	if (var->a->sz_ < 2)
		return (TRUE);
	back = pop_back(var->a);
	push_front(var->a, back);
	if (var->exec_st->tail->exec == RB)
	{
		pop_back(var->exec_st);
		push_back(var->exec_st, init_node(0, 0, RR));
	}
	else
		push_back(var->exec_st, init_node(0, 0, RA));
	return (TRUE);
}

t_bool	rb(t_var *var)
{
	t_node	*back;

	if (var->b->sz_ < 2)
		return (TRUE);
	back = pop_back(var->b);
	push_front(var->b, back);
	if (var->exec_st->tail->exec == RA)
	{
		pop_back(var->exec_st);
		push_back(var->exec_st, init_node(0, 0, RR));
	}
	else
		push_back(var->exec_st, init_node(0, 0, RB));
	return (TRUE);
}
