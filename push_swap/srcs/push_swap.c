/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:26:12 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/27 14:26:40 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc < 3)
		ft_exit_with_error(0);
	a = init_stack();
	b = init_stack();
	i = 0;
	while (++i < argc)
		push_back(a, ft_atoi(argv[i]));
	
	return (0);
}
