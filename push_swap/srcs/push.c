/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:22:23 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/25 23:01:26 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_bool	push_a(t_stack *a, t_stack *b);
t_bool	push_b(t_stack *a, t_stack *b);

t_bool	push_a(t_stack *a, t_stack *b)
{
	int	b_top;

	if (!b->sz_)
		return (FALSE);
	b_top = pop_back(b);
	push_back(a, b_top);
	return (TRUE);
}

t_bool	push_b(t_stack *a, t_stack *b)
{
	int	a_top;

	if (!a->sz_)
		return (FALSE);
	a_top = pop_back(a);
	push_back(b, a_top);
	return (TRUE);
}
