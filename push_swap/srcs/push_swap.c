/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:26:12 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 22:16:10 by younhwan         ###   ########.fr       */
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
	sort_stack(var, 0, var->a->sz_);
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
	parse_input(ret->a, argc, argv);
	ret->arr = init_arr(ret->a);
	return (ret);
}
