/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:14:09 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/13 22:58:15 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	pa(t_var *var);
t_bool	pb(t_var *var);

t_bool	pa(t_var *var)
{
	if (!var->b->sz_)
		return (TRUE);
	push_back(var->a, pop_back(var->b));
	push_back(var->exec_st, init_node(0, 0, PA));
	return (TRUE);
}

t_bool	pb(t_var *var)
{
	if (!var->a->sz_)
		return (TRUE);
	push_back(var->b, pop_back(var->a));
	push_back(var->exec_st, init_node(0, 0, PB));
	return (TRUE);
}
