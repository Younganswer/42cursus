/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:36:00 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/14 17:54:31 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/sort_small.h"

t_bool			sort_small_4(t_var *var);
static t_bool	tail_is_1(t_var *var);
static t_bool	head_is_1(t_var *var);
static t_bool	head_next_is_1(t_var *var);
static t_bool	tail_prev_is_1(t_var *var);

t_bool	sort_small_4(t_var *var)
{
	if (var->a->head->val == 1)
		head_is_1(var);
	else if (var->a->tail->val == 1)
		tail_is_1(var);
	else if (var->a->head->next->val == 1)
		head_next_is_1(var);
	else if (var->a->tail->prev->val == 1)
		tail_prev_is_1(var);
	return (TRUE);
}

static t_bool	head_is_1(t_var *var)
{
	if (var->a->tail->val == 2 && var->a->tail->prev->val == 3)
		return (rra(var));
	if (var->a->tail->val == 2 && var->a->tail->prev->val == 4)
		return (ra(var) && sa(var) && rra(var) && rra(var));
	if (var->a->head->next->val == 2 && var->a->tail->val == 3)
		return (rra(var) && rra(var) && sa(var));
	if (var->a->head->next->val == 2 && var->a->tail->val == 4)
		return (sa(var) && rra(var) && rra(var) && sa(var));
	if (var->a->tail->prev->val == 2 && var->a->tail->val == 3)
		return (sa(var) && rra(var));
	if (var->a->tail->prev->val == 2 && var->a->tail->val == 4)
		return (rra(var) && sa(var) && ra(var));
	return (TRUE);
}

static t_bool	tail_is_1(t_var *var)
{
	pb(var);
	sort_small_3(var);
	pa(var);
	return (FALSE);
}

static t_bool	head_next_is_1(t_var *var)
{
	if (var->a->head->val == 2 && var->a->tail->val == 3)
		return (ra(var) && ra(var));
	if (var->a->head->val == 2 && var->a->tail->val == 4)
		return (sa(var) && ra(var) && ra(var));
	if (var->a->tail->val == 2 && var->a->head->val == 3)
		return (rra(var) && sa(var) && rra(var));
	if (var->a->tail->val == 2 && var->a->head->val == 4)
		return (rra(var) && rra(var) && sa(var) && ra(var));
	if (var->a->tail->prev->val == 2 && var->a->tail->val == 4)
		return (ra(var) && sa(var));
	if (var->a->tail->prev->val == 2 && var->a->head->val == 4)
		return (rra(var) && sa(var) && ra(var) && ra(var) && sa(var));
	return (TRUE);
}

static t_bool	tail_prev_is_1(t_var *var)
{
	if (var->a->tail->val == 2 && var->a->head->val == 4)
		return (sa(var));
	if (var->a->tail->val == 2 && var->a->head->val == 3)
		return (pb(var) && pb(var) && sa(var) && sb(var) && pa(var) && pa(var));
	if (var->a->head->val == 2 && var->a->tail->val == 4)
		return (ra(var) && pb(var) && sa(var) && pa(var));
	if (var->a->head->val == 2 && var->a->tail->val == 3)
		return (pb(var) && sa(var) && pa(var) && ra(var) && ra(var));
	if (var->a->head->next->val == 2 && var->a->head->val == 4)
		return (rra(var) && sa(var) && ra(var) && ra(var));
	if (var->a->head->next->val == 2 && var->a->tail->val == 4)
		return (ra(var));
	return (TRUE);
}
