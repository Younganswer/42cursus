/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:36:16 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 17:21:54 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.h"

t_stack	*init_stack(void)
{
	t_stack	*ret;

	ret = (t_stack *) malloc(sizeof(t_stack));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	ft_memset(ret, 0, sizeof(t_stack));
	return (ret);
}
