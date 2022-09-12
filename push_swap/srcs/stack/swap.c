/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:11:38 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:07:20 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	sa(t_var *var);
t_bool	sb(t_var *var);

t_bool	sa(t_var *var)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (var->a->sz_ < 2)
		return (TRUE);
	tmp1 = pop_back(var->a);
	tmp2 = pop_back(var->a);
	push_back(var->a, tmp1);
	push_back(var->a, tmp2);
	if (var->exec_st->tail->exec == SB)
	{
		pop_back(var->exec_st);
		push_back(var->exec_st, init_node(0, 0, SS));
	}
	else
		push_back(var->exec_st, init_node(0, 0, SA));
	return (TRUE);
}

t_bool	sb(t_var *var)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (var->b->sz_ < 2)
		return (TRUE);
	tmp1 = pop_back(var->b);
	tmp2 = pop_back(var->b);
	push_back(var->b, tmp1);
	push_back(var->b, tmp2);
	if (var->exec_st->tail->exec == SA)
	{
		pop_back(var->exec_st);
		push_back(var->exec_st, init_node(0, 0, SS));
	}
	else
		push_back(var->exec_st, init_node(0, 0, SB));
	return (TRUE);
}
