/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:36:00 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/12 15:22:16 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_small.h"

t_bool	sort_small(t_var *var);

t_bool	sort_small(t_var *var)
{
	if (var->a->sz_ == 2)
		sort_small_2(var);
	else if (var->a->sz_ == 3)
		sort_small_3(var);
	else if (var->a->sz_ == 4)
		sort_small_4(var);
	else if (var->a->sz_ == 5)
		sort_small_5(var);
	return (TRUE);
}
