/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:09:02 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/18 13:14:30 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	free_stack(t_stack *st);
void	print_exec(t_stack *st);
t_bool	is_sorted(t_stack *st);

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

void	print_exec(t_stack *st)
{
	while (st->head)
	{
		if (st->head->exec == SA && ft_printf("sa\n"))
			st->head = st->head->next;
		else if (st->head->exec == SB && ft_printf("sb\n"))
			st->head = st->head->next;
		else if (st->head->exec == SS && ft_printf("ss\n"))
			st->head = st->head->next;
		else if (st->head->exec == PA && ft_printf("pa\n"))
			st->head = st->head->next;
		else if (st->head->exec == PB && ft_printf("pb\n"))
			st->head = st->head->next;
		else if (st->head->exec == RA && ft_printf("ra\n"))
			st->head = st->head->next;
		else if (st->head->exec == RB && ft_printf("rb\n"))
			st->head = st->head->next;
		else if (st->head->exec == RR && ft_printf("rr\n"))
			st->head = st->head->next;
		else if (st->head->exec == RRA && ft_printf("rra\n"))
			st->head = st->head->next;
		else if (st->head->exec == RRB && ft_printf("rrb\n"))
			st->head = st->head->next;
		else if (st->head->exec == RRR && ft_printf("rrr\n"))
			st->head = st->head->next;
	}
}

t_bool	is_sorted(t_stack *st)
{
	t_node	*tmp;

	if (st->sz_ <= 1)
		return (TRUE);
	tmp = st->tail;
	while (tmp->prev)
	{
		if (tmp->val > tmp->prev->val)
			return (FALSE);
		tmp = tmp->prev;
	}
	return (TRUE);
}
