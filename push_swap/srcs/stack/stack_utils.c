/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:09:02 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/16 18:34:39 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	free_stack(t_stack *st);
t_bool	print_exec(t_stack *st);
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

t_bool	print_exec(t_stack *st)
{
	while (st->head)
	{
		if (st->head->exec == SA)
			ft_putendl_fd("sa", 1);
		else if (st->head->exec == SB)
			ft_putendl_fd("sb", 1);
		else if (st->head->exec == SS)
			ft_putendl_fd("ss", 1);
		else if (st->head->exec == PA)
			ft_putendl_fd("pa", 1);
		else if (st->head->exec == PB)
			ft_putendl_fd("pb", 1);
		else if (st->head->exec == RA)
			ft_putendl_fd("ra", 1);
		else if (st->head->exec == RB)
			ft_putendl_fd("rb", 1);
		else if (st->head->exec == RRA)
			ft_putendl_fd("rra", 1);
		else if (st->head->exec == RRB)
			ft_putendl_fd("rrb", 1);
		else if (st->head->exec == RRR)
			ft_putendl_fd("rrr", 1);
		st->head = st->head->next;
	}
	return (TRUE);
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
