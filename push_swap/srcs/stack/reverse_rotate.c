/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:38:23 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/11 17:46:26 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	rra(t_stack *a);
t_bool	rrb(t_stack *a);
t_bool	rrr(t_stack *a, t_stack*b);

t_bool	rra(t_stack *a)
{
	t_node	*front;

	if (a->sz_ < 2)
		return (TRUE);
	front = pop_front(a);
	push_back(a, front);
	ft_putstr_fd("rra\n", 1);
	return (TRUE);
}

t_bool	rrb(t_stack *b)
{
	t_node	*front;

	if (b->sz_ < 2)
		return (TRUE);
	front = pop_front(b);
	push_back(b, front);
	ft_putstr_fd("rrb\n", 1);
	return (TRUE);
}

t_bool	rrr(t_stack *a, t_stack *b)
{
	t_node	*front;

	if (2 <= a->sz_)
	{
		front = pop_front(a);
		push_back(a, front);
	}
	if (2 <= b->sz_)
	{
		front = pop_front(b);
		push_back(b, front);
	}
	ft_putstr_fd("rrr\n", 1);
	return (TRUE);
}
