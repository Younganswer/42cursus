/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:26:12 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/11 01:03:45 by younhwan         ###   ########.fr       */
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
	divide(var);
	// if (var->a->sz_ <= 5)
		// return (sort_small(var));
	merge(var);
	// print_stack(var->a);
	return (0);
}

static t_var	*init_var(int argc, char **argv)
{
	t_var	*ret;
	t_node	*to_insert;

	ret = (t_var *) malloc(sizeof(t_var));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	ret->a = init_stack();
	ret->b = init_stack();
	parse_input(ret->a, argc, argv);
	if (has_duplicated(ret->a))
		ft_exit_with_error(0, EXIT_SUCCESS);
	ret->size_of_triangles_in_a = init_stack();
	ret->size_of_triangles_in_b = init_stack();
	to_insert = init_node(ret->a->sz_, NORMAL);
	push_back(ret->size_of_triangles_in_a, to_insert);
	ret->a_to_b = TRUE;
	return (ret);
}
