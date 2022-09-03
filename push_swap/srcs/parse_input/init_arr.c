/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:15:16 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 17:21:10 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parse_input.h"

t_arr			*init_arr(t_stack *a);
static int		*stack_to_arr(t_stack *a);

t_arr	*init_arr(t_stack *a)
{
	t_arr	*ret;

	ret = (t_arr *) malloc(sizeof(t_arr));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	ret->chunk = stack_to_arr(a);
	ret->sz_ = a->sz_;
	return (ret);
}

static int	*stack_to_arr(t_stack *a)
{
	t_node	*tmp;
	int		*ret;
	int		i;

	ret = (int *) malloc(sizeof(int) * (a->sz_));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	i = 0;
	tmp = a->head;
	while (tmp)
	{
		ret[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	return (ret);
}
