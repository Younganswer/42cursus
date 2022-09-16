/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:52:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/16 18:35:18 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/checker_bonus.h"

static t_var	*init_var(int argc, char **argv);
static t_bool	exec_cmd(t_var *var, const char *cmd);

int	main(int argc, char **argv)
{
	t_var	*var;
	char	*cmd;

	if (argc == 1)
		return (0);
	var = init_var(argc, argv);
	while (TRUE)
	{
		cmd = get_next_line(0);
		if (!cmd || cmd[0] == '\n')
		{
			free(cmd);
			break ;
		}
		exec_cmd(var, cmd);
		free(cmd);
	}
	if (is_sorted(var->a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
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
	ret->exec_st = init_stack();
	return (ret);
}

static t_bool	exec_cmd(t_var *var, const char *cmd)
{
	if (!ft_strncmp("sa", cmd, 2))
		sa(var);
	else if (!ft_strncmp("sb", cmd, 2))
		sb(var);
	else if (!ft_strncmp("ss", cmd, 2))
		ss(var);
	else if (!ft_strncmp("pa", cmd, 2))
		pa(var);
	else if (!ft_strncmp("pb", cmd, 2))
		pb(var);
	else if (!ft_strncmp("ra", cmd, 2))
		ra(var);
	else if (!ft_strncmp("rb", cmd, 2))
		rb(var);
	else if (!ft_strncmp("rr", cmd, 2))
		rr(var);
	else if (!ft_strncmp("rra", cmd, 3))
		rra(var);
	else if (!ft_strncmp("rrb", cmd, 3))
		rrb(var);
	else if (!ft_strncmp("rrr", cmd, 3))
		rrr(var);
	else
		ft_exit_with_error(0, EXIT_SUCCESS);
	return (TRUE);
}
