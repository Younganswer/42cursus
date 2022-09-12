/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:36:00 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:21:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_small.h"

t_bool	sort_small_2(t_var *var);

t_bool	sort_small_2(t_var *var)
{
	if (var->a->head->val < var->a->tail->val)
		sa(var);
	return (TRUE);
}
