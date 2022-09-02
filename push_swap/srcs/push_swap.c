/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:26:12 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/02 14:56:53 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static t_arr	*read_arguments(t_stack *a, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_arr	*arr;
	int		sz_;

	if (argc < 3)
		ft_exit_with_error(0, EXIT_SUCCESS);
	a = init_stack();
	b = init_stack();
	arr = read_arguments(a, argc, argv);
	(void) arr;
	(void) b;
	return (0);
}

static t_arr	*read_arguments(t_stack *a, int argc, char **argv)
{
	t_arr	*ret;

	ret = (t_arr *) malloc(sizeof(t_arr));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	ret->chunk = parse_input(a, argc, argv);
	ret->sz_ = a->sz_;
	return (ret);
}