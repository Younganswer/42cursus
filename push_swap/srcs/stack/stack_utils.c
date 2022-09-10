/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:09:02 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/10 21:39:52 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	free_stack(t_stack *st);
t_bool	print_stack(t_stack *st);
t_bool	swap(int *a, int *b);

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

t_bool	print_stack(t_stack *st)
{
	t_node	*tmp;

	tmp = st->tail;
	while (tmp)
	{
		for (int i=0; i<tmp->val; i++) {
			ft_putchar_fd('-', 1);
		}
		ft_putchar_fd('\n', 1);
		// ft_putstr_fd(ft_itoa(tmp->val), 1);
		// ft_putchar_fd(' ', 1);
		// (tmp->shape == NORMAL) ? ft_putendl_fd("N", 1) : ft_putendl_fd("R", 1);
		tmp = tmp->prev;
	}
	return (TRUE);
}
