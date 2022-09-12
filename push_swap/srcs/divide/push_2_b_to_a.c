/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_2_b_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:39:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:14:50 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"

t_bool	push_2_b_to_a(t_var *var, t_shape shape)
{
	pa(var);
	pa(var);
	if ((var->a->tail->val < var->a->tail->prev->val && shape == REVERSED) \
		|| (var->a->tail->prev->val < var->a->tail->val && shape == NORMAL))
		sa(var);
	return (TRUE);
}
