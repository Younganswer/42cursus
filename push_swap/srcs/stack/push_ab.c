/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:14:09 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/31 23:34:42 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_bool	push_a(t_stack *a, t_stack *b);
t_bool	push_b(t_stack *a, t_stack *b);

t_bool	push_a(t_stack *a, t_stack *b)
{
	int	top;

	if (!b->sz_)
		return (FALSE);
	top = pop_back(b);
	push_back(a, top);
	return (TRUE);
}

t_bool	push_b(t_stack *a, t_stack *b)
{
	int	top;

	if (!a->sz_)
		return (FALSE);
	top = pop_back(a);
	push_back(b, top);
	return (TRUE);
}
