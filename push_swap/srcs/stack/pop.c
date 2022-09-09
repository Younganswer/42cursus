/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:08:51 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 22:05:01 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_node	*pop_front(t_stack *st);
t_node	*pop_back(t_stack *st);

t_node	*pop_front(t_stack *st)
{
	t_node	*ret;

	if (!st || (!st->head && !st->tail))
		return (0);
	ret = st->head;
	if (st->head == st->tail)
	{
		st->head = 0;
		st->tail = 0;
	}
	else
	{
		st->head = st->head->next;
		st->head->prev = 0;
	}
	st->sz_--;
	return (ret);
}

t_node	*pop_back(t_stack *st)
{
	t_node	*ret;

	if (!st || (!st->head && !st->tail))
		return (0);
	ret = st->tail;
	if (st->head == st->tail)
	{
		st->head = 0;
		st->tail = 0;
	}
	else
	{
		st->tail = st->tail->prev;
		st->tail->next = 0;
	}
	st->sz_--;
	return (ret);
}
