/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:28:55 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 21:26:49 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	ra(t_stack *a);
t_bool	rb(t_stack *b);
t_bool	rr(t_stack *a, t_stack *b);

t_bool	ra(t_stack *a)
{
	t_node	*back;

	if (a->sz_ < 2)
		return (TRUE);
	back = pop_back(a);
	push_front(a, back);
	ft_putstr_fd("ra\n", 1);
	return (TRUE);
}

t_bool	rb(t_stack *b)
{
	t_node	*back;

	if (b->sz_ < 2)
		return (TRUE);
	back = pop_back(b);
	push_front(b, back);
	ft_putstr_fd("rb\n", 1);
	return (TRUE);
}

t_bool	rr(t_stack *a, t_stack *b)
{
	t_node	*back;

	if (2 <= a->sz_)
	{
		back = pop_back(a);
		push_front(a, back);
	}
	if (2 <= b->sz_)
	{
		back = pop_back(b);
		push_front(b, back);
	}
	ft_putstr_fd("rr\n", 1);
	return (TRUE);
}
