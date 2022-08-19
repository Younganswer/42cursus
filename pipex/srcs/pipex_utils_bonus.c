/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:14:25 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/19 19:24:58 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void		execute(char **argv, int cmd_idx, char **envp);
int			open_file(const char *file, t_open_flag flag);
void		exit_with_error(void);
void		usage(void);
static char	*find_path(char *cmd, char **envp);

void	exit_with_error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	execute(char **argv, int cmd_idx, char **envp)
{
	char	**cmd;
	char	*cmd_path;
	int		i;

	cmd = ft_split(argv[cmd_idx], ' ');
	cmd_path = find_path(cmd[0], envp);
	if (!cmd_path)
	{
		if (STDIN_FILENO != 0 || (STDIN_FILENO == 0 && 2 < cmd_idx))
		{
			ft_putstr_fd("zsh: command not found: ", 2);
			ft_putstr_fd(cmd[0], 2);
			ft_putstr_fd("\n", 2);
		}
		exit(EXIT_FAILURE);
	}
	if (STDIN_FILENO != 0 || (STDIN_FILENO == 0 && 2 < cmd_idx))
		if (execve(cmd_path, cmd, envp) == -1)
			exit_with_error();
	free(cmd_path);
	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
}

void	usage(void)
{
	ft_putstr_fd("\033[31mError: Invalid argument\033[0m\n", 2);
	ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("HERE_DOC: ./pipex \"here_doc\" \
		<LIMITER> <cmd> <cmd1> <...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

int	open_file(const char *file, t_open_flag flag)
{
	int	fd;

	fd = 0;
	if (flag == HERE_DOC)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (flag == FILE_OUT)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (flag == FILE_IN)
		fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		perror("\033[31mError");
	return (fd);
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
