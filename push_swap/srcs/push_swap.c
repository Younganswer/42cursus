/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:26:12 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 15:00:16 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static t_var	*init_var(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc == 1)
		return (0);
	var = init_var(argc, argv);
	if (var->a->sz_ <= 1)
		return (0);
	sort_stack(var);
	return (0);
}

static t_var	*init_var(int argc, char **argv)
{
	t_var	*ret;

	ret = (t_var *) malloc(sizeof(t_var));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	ret->a = init_stack();
	ret->b = init_stack();
	ret->a_tri_sz = init_stack();
	ret->b_tri_sz = init_stack();
	parse_input(ret->a, argc, argv);
	return (ret);
}
