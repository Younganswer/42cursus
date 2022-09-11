/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:14:09 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/11 16:34:25 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	pa(t_stack *a, t_stack *b);
t_bool	pb(t_stack *a, t_stack *b);

t_bool	pa(t_stack *a, t_stack *b)
{
	t_node	*top;

	if (!b->sz_)
		return (TRUE);
	top = pop_back(b);
	push_back(a, top);
	ft_putstr_fd("pa\n", 1);
	return (TRUE);
}

t_bool	pb(t_stack *a, t_stack *b)
{
	t_node	*top;

	if (!a->sz_)
		return (TRUE);
	top = pop_back(a);
	push_back(b, top);
	ft_putstr_fd("pb\n", 1);
	return (TRUE);
}
