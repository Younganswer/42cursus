/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:08:51 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 17:21:55 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

int		pop_front(t_stack *st);
int		pop_back(t_stack *st);

int	pop_front(t_stack *st)
{
	int	ret;

	if (!st || (!st->head && !st->tail))
		return (-1);
	ret = st->head->val;
	if (st->head == st->tail)
	{
		free(st->head);
		st->head = 0;
		st->tail = 0;
	}
	else
	{
		st->head = st->head->next;
		free(st->head->prev);
		st->head->prev = 0;
	}
	st->sz_--;
	return (ret);
}

int	pop_back(t_stack *st)
{
	int	ret;

	if (!st || (!st->head && !st->tail))
		return (-1);
	ret = st->tail->val;
	if (st->head == st->tail)
	{
		free(st->tail);
		st->head = 0;
		st->tail = 0;
	}
	else
	{
		st->tail = st->tail->prev;
		free(st->tail->next);
		st->tail->next = 0;
	}
	st->sz_--;
	return (ret);
}
