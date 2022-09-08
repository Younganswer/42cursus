/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:15:43 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/08 14:19:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_stack.h"

t_bool	is_sorted(t_stack *a);

t_bool	is_sorted(t_stack *a)
{
	t_node	*tmp;

	tmp = a->head;
	while (tmp->next)
	{
		if (tmp->val < tmp->next->val)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}
