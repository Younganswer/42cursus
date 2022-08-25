/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:28:55 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/25 23:00:51 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_bool	ra(t_stack *a);
t_bool	rb(t_stack *b);
t_bool	rra(t_stack *a);
t_bool	rrb(t_stack *b);

t_bool	ra(t_stack *a)
{
	int	top;

	if (!a->sz_)
		return (FALSE);
	if (!(a->sz_ == 1))
		return (TRUE);
	top = pop_front(a);
	push_back(a, top);
	return (TRUE);
}

t_bool	rb(t_stack *b)
{
	int	top;

	if (!b->sz_)
		return (FALSE);
	if (!(b->sz_ == 1))
		return (TRUE);
	top = pop_front(b);
	push_back(b, top);
	return (TRUE);
}

t_bool	rra(t_stack *a)
{
	int	top;

	if (!a->sz_)
		return (FALSE);
	if (!(a->sz_ == 1))
		return (TRUE);
	top = pop_back(a);
	push_front(a, top);
	return (TRUE);
}

t_bool	rrb(t_stack *b)
{
	int	top;

	if (!b->sz_)
		return (FALSE);
	if (!(b->sz_ == 1))
		return (TRUE);
	top = pop_back(b);
	push_front(b, top);
	return (TRUE);
}
