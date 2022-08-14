/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:14:25 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/13 18:40:29 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void		exit_with_error(const char *str);
void		execute(char *file, char **envp);
static char	*find_path(char *cmd, char **envp);

void	exit_with_error(const char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	execute(char *file, char **envp)
{
	char	**cmd;
	char	*cmd_path;
	int		i;
	
	cmd = ft_split(file, ' ');
	cmd_path = find_path(cmd[0], envp);
	if (!cmd_path)
	{
		i = -1;
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit_with_error("\033[31mError: Invalid command\033[0m\n");
	}
	if (execve(cmd_path, cmd, envp) == -1)
		exit_with_error("\033[31mError: Unable to execute command\033[0m\n");
	free(cmd_path);
	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
	return ;
}

static char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}
