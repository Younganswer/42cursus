/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:09:02 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/25 23:05:22 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int		pop_front(t_stack *st);
t_bool	push_front(t_stack *st, int num);
int		pop_back(t_stack *st);
t_bool	push_back(t_stack *st, int num);
t_bool	free_stack(t_stack *st);

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
		st->tail->next = to_insert;
		to_insert->prev = st->tail;
		st->tail = to_insert;
	}
	st->sz_++;
	return (TRUE);
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

t_bool	free_stack(t_stack *st)
{
	t_node	*tmp;

	while (st->head)
	{
		tmp = st->head;
		st->head = st->head->next;
		free(tmp);
	}
	free(st);
	return (TRUE);
}
