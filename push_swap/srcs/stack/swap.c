/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:11:38 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 20:00:24 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool			sa(t_stack *a);
t_bool			sb(t_stack *b);
t_bool			ss(t_stack *a, t_stack *b);
static t_bool	swap(int *a, int *b);

t_bool	sa(t_stack *a)
{
	if (a->sz_ < 2)
		return (TRUE);
	swap(&a->tail->prev->val, &a->tail->val);
	ft_putstr_fd("sa\n", 1);
	return (TRUE);
}

t_bool	sb(t_stack *b)
{
	if (b->sz_ < 2)
		return (TRUE);
	swap(&b->tail->prev->val, &b->tail->val);
	ft_putstr_fd("sb\n", 1);
	return (TRUE);
}

t_bool	ss(t_stack *a, t_stack *b)
{
	swap(&a->tail->prev->val, &a->tail->val);
	swap(&b->tail->prev->val, &b->tail->val);
	ft_putstr_fd("ss\n", 1);
	return (TRUE);
}

static t_bool	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (TRUE);
}
