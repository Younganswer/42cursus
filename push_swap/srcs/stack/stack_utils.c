/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:09:02 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/27 14:27:37 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_bool	free_stack(t_stack *st);
t_bool	print_stack(t_stack *st);

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

	tmp = st->head;
	while (tmp)
	{
		ft_printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	ft_printf("\n");
	return (TRUE);
}
