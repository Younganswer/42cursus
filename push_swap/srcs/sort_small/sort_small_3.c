/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:36:00 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:22:22 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_small.h"

t_bool	sort_small_3(t_var *var);

t_bool	sort_small_3(t_var *var)
{
	if (var->a->head->val < var->a->tail->val && \
		var->a->head->next->val < var->a->tail->val)
		ra(var);
	else if (var->a->tail->val < var->a->head->val && \
		var->a->tail->prev->val < var->a->head->val)
		rra(var);
	if (var->a->tail->prev->val < var->a->tail->val)
		sa(var);
	return (TRUE);
}
