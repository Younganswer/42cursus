/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:26:12 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 15:06:55 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static t_var	*init_var(int argc, char **argv);
static t_arr	*read_arguments(t_stack *a, int argc, char **argv);
static int		*stack_to_arr(t_stack *a);

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc < 3)
		ft_exit_with_error(0, EXIT_SUCCESS);
	var = init_var(argc, argv);
	print_stack(var->a);
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
	ret->b = init_stack();
	ret->arr = read_arguments(ret->a, argc, argv);
	return (ret);
}

static t_arr	*read_arguments(t_stack *a, int argc, char **argv)
{
	t_arr	*ret;

	ret = (t_arr *) malloc(sizeof(t_arr));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	parse_input(a, argc, argv);
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
