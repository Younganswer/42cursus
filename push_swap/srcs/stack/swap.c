/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:11:38 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 21:31:46 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_bool	sa(t_stack *a);
t_bool	sb(t_stack *b);
t_bool	ss(t_stack *a, t_stack *b);

t_bool	sa(t_stack *a)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (a->sz_ < 2)
		return (TRUE);
	tmp1 = pop_back(a);
	tmp2 = pop_back(a);
	push_back(a, tmp1);
	push_back(a, tmp2);
	ft_putstr_fd("sa\n", 1);
	return (TRUE);
}

t_bool	sb(t_stack *b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (b->sz_ < 2)
		return (TRUE);
	tmp1 = pop_back(b);
	tmp2 = pop_back(b);
	push_back(b, tmp1);
	push_back(b, tmp2);
	ft_putstr_fd("sb\n", 1);
	return (TRUE);
}

t_bool	ss(t_stack *a, t_stack *b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (a->sz_ < 2 && b->sz_ < 2)
		return (TRUE);
	if (2 <= a->sz_)
	{
		tmp1 = pop_back(a);
		tmp2 = pop_back(a);
		push_back(a, tmp1);
		push_back(a, tmp2);
	}	
	if (2 <= b->sz_)
	{
		tmp1 = pop_back(b);
		tmp2 = pop_back(b);
		push_back(b, tmp1);
		push_back(b, tmp2);
	}
	ft_putstr_fd("ss\n", 1);
	return (TRUE);
}
