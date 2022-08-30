/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:28:55 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/27 14:24:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_bool	rotate(t_stack *st);
t_bool	reverse_rotate(t_stack *st);

t_bool	rotate(t_stack *st)
{
	int	back;

	if (!st->sz_)
		return (FALSE);
	if (st->sz_ == 1)
		return (TRUE);
	back = pop_back(st);
	push_front(st, back);
	return (TRUE);
}

t_bool	reverse_rotate(t_stack *st)
{
	int	front;

	if (!st->sz_)
		return (FALSE);
	if (st->sz_ == 1)
		return (TRUE);
	front = pop_front(st);
	push_back(st, front);
	return (TRUE);
}
