/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:11:38 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/25 23:01:11 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_bool	swap(t_stack *st);

t_bool	swap(t_stack *st)
{
	int	top1;
	int	top2;

	if (st->sz_ < 2)
		return (FALSE);
	top1 = pop_back(st);
	top2 = pop_back(st);
	push_back(st, top1);
	push_back(st, top2);
	return (TRUE);
}
