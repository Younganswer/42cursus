/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:36:00 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/14 17:47:50 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_small.h"

t_bool		sort_small_5(t_var *var);

t_bool	sort_small_5(t_var *var)
{
	int		exec_pb;

	exec_pb = 0;
	while (exec_pb < 2)
	{
		if (var->a->tail->val <= 2)
		{
			pb(var);
			exec_pb++;
		}
		else
			ra(var);
	}
	sort_small_3(var);
	if (var->b->tail->val < var->b->head->val)
		sb(var);
	pa(var);
	pa(var);
	return (TRUE);
}
