/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:10:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 21:24:59 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	push_front(t_stack *st, t_node *to_insert);
t_bool	push_back(t_stack *st, t_node *to_insert);

t_bool	push_front(t_stack *st, t_node *to_insert)
{
	if (!st->head && !st->tail)
	{
		st->head = to_insert;
		st->tail = to_insert;
	}
	else
	{
		st->head->prev = to_insert;
		to_insert->next = st->head;
		st->head = to_insert;
	}
	st->sz_++;
	return (TRUE);
}

t_bool	push_back(t_stack *st, t_node *to_insert)
{
	if (!st->head && !st->tail)
	{
		st->head = to_insert;
		st->tail = to_insert;
	}
	else
	{
		st->tail->next = to_insert;
		to_insert->prev = st->tail;
		st->tail = to_insert;
	}
	st->sz_++;
	return (TRUE);
}
