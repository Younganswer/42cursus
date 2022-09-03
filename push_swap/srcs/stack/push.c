/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:10:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 17:21:55 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	push_front(t_stack *st, int num);
t_bool	push_back(t_stack *st, int num);

t_bool	push_front(t_stack *st, int num)
{
	t_node	*to_insert;

	to_insert = init_node(num);
	if (!to_insert)
		return (FALSE);
	if (!st->head && !st->tail)
	{
		st->head = to_insert;
		st->tail = to_insert;
		return (TRUE);
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

t_bool	push_back(t_stack *st, int num)
{
	t_node	*to_insert;

	to_insert = init_node(num);
	if (!to_insert)
		return (FALSE);
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
