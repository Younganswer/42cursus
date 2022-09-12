/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:36:00 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:22:24 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_small.h"

t_bool		sort_small_4(t_var *var);
static int	get_pivot(t_var *var);

t_bool	sort_small_4(t_var *var)
{
	int		pivot;
	t_node	*tmp;
	int		exec_pb;

	pivot = get_pivot(var);
	tmp = var->a->head;
	exec_pb = 0;
	while (exec_pb < 2)
	{
		if (tmp->val <= pivot)
		{
			pb(var);
			exec_pb++;
		}
		else
			ra(var);
		tmp = tmp->next;
	}
	if (var->a->head->val < var->a->tail->val)
		sa(var);
	else if (var->b->tail->val < var->b->head->val)
		sb(var);
	pa(var);
	pa(var);
	return (TRUE);
}

static int	get_pivot(t_var *var)
{
	int 	arr[4];
	t_node	*tmp;
	int		i;

	tmp = var->a->head;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->val;
		tmp = tmp->next;
	}
	sort_arr(arr, 0, 3);
	return (arr[1]);
}
