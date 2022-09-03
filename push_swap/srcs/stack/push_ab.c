/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:14:09 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 17:42:45 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	push_a(t_stack *a, t_stack *b);
t_bool	push_b(t_stack *a, t_stack *b);

t_bool	push_a(t_stack *a, t_stack *b)
{
	int	top;

	if (!b->sz_)
		return (FALSE);
	top = pop_back(b);
	push_back(a, top);
	ft_putstr_fd("pa\n", 1);
	return (TRUE);
}

t_bool	push_b(t_stack *a, t_stack *b)
{
	int	top;

	if (!a->sz_)
		return (FALSE);
	top = pop_back(a);
	push_back(b, top);
	ft_putstr_fd("pb\n", 1);
	return (TRUE);
}
