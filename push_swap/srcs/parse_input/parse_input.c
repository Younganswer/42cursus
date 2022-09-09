/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:26:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 15:04:28 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parse_input.h"

t_bool		parse_input(t_stack *a, int argc, char **argv);
static char	**split_argv(char *input);
static void	push_arguments_to_stack(t_stack *a, char **splited_argv);

t_bool	parse_input(t_stack *a, int argc, char **argv)
{
	char	**splited_argv;
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (is_not_integer(argv[i]))
			ft_exit_with_error(0, EXIT_SUCCESS);
		splited_argv = split_argv(argv[i]);
		push_arguments_to_stack(a, splited_argv);
		free(splited_argv);
	}
	if (has_duplicated(a))
		ft_exit_with_error(0, EXIT_SUCCESS);
	return (TRUE);
}

static char	**split_argv(char *input)
{
	char		**ret;
	size_t		i;

	if (is_not_integer(input))
		ft_exit_with_error(0, EXIT_SUCCESS);
	i = 0;
	while (input[i] && input[i] == ' ')
		i++;
	ret = ft_split(&input[i], ' ');
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	return (ret);
}

static void	push_arguments_to_stack(t_stack *a, char **splited_argv)
{
	int	i;

	i = 0;
	while (splited_argv[i])
	{
		push_front(a, ft_atoi(splited_argv[i]));
		i++;
	}
	return ;
}

