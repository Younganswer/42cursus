/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:26:12 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/01 13:45:19 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static int	*init_sorted_arr(int argc, char **argv);
static void	init_a(t_stack *a, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;

	if (argc < 3)
		ft_exit_with_error(0, EXIT_SUCCESS);
	a = init_stack();
	b = init_stack();
	arr = init_sorted_arr(argc, argv);
	init_a(a, argc, argv);
	(void) arr;
	(void) b;
	return (0);
}

static int	*init_sorted_arr(int argc, char **argv)
{
	int	*ret;
	int	i;

	ret = (int *) malloc(sizeof(int) * (argc - 1));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	i = 0;
	while (++i < argc)
		ret[i - 1] = ft_atoi(argv[i]);
	sort(ret, 0, argc - 2);
	if (has_duplicated(ret, argc - 1))
		ft_exit_with_error(0, EXIT_SUCCESS);
	return (ret);
}

static void	init_a(t_stack *a, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		push_back(a, ft_atoi(argv[i]));
	return ;
}
