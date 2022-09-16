/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:26:12 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/16 20:05:51 by younhwan         ###   ########.fr       */
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
	if (is_sorted(var->a))
		return (0);
	if (var->a->sz_ <= 5)
		sort_small(var);
	else
	{
		divide(var);
		merge(var);
	}
	print_exec(var->exec_st);
	return (0);
}

static t_var	*init_var(int argc, char **argv)
{
	t_var	*ret;

	ret = (t_var *) malloc(sizeof(t_var));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	ft_memset(ret, 0, sizeof(t_var));
	ret->a = init_stack();
	parse_input(ret->a, argc, argv);
	if (has_duplicated(ret->a))
		ft_exit_with_error(0, EXIT_SUCCESS);
	ret->b = init_stack();
	ret->size_of_triangles_in_a = init_stack();
	ret->size_of_triangles_in_b = init_stack();
	ret->exec_st = init_stack();
	push_back(ret->size_of_triangles_in_a, init_node(ret->a->sz_, NORMAL, 0));
	ret->a_to_b = TRUE;
	return (ret);
}
