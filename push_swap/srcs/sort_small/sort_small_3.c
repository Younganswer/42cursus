/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:36:00 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/14 16:01:20 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_small.h"

t_bool	sort_small_3(t_var *var);

t_bool	sort_small_3(t_var *var)
{
	if (var->a->head->val < var->a->tail->val && \
		var->a->head->next->val < var->a->tail->val)
		ra(var);
	else if (var->a->head->val < var->a->head->next->val && \
			var->a->tail->val < var->a->head->next->val)
		rra(var);
	if (var->a->tail->prev->val < var->a->tail->val)
		sa(var);
	return (TRUE);
}
