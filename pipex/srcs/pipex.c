/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:20:18 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/23 22:34:09 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	here_doc(int argc, const char *end_flag);
static void	get_stdin(int *fd, const char *end_flag);
static void	child_process(int argc, char **argv, char **envp, int cmd_idx);
static void	set_fd(int argc, char **argv, int cmd_idx);

int	main(int argc, char **argv, char **envp)
{
	int	cmd_idx;

	if (argc < 5)
		usage();
	cmd_idx = 3;
	if (!ft_strncmp(argv[1], "here_doc", 8))
		here_doc(argc, argv[2]);
	else
		cmd_idx--;
	child_process(argc, argv, envp, cmd_idx);
	return (0);
}

static void	here_doc(int argc, const char *end_flag)
{
	pid_t	reader;
	int		fd[2];

	if (argc < 6)
		usage();
	if (pipe(fd) == -1)
		exit_with_error();
	reader = fork();
	if (reader == -1)
		exit_with_error();
	if (!reader)
		get_stdin(fd, end_flag);
	else
	{
		close(fd[WRITE]);
		dup2(fd[READ], STDIN_FILENO);
		close(fd[READ]);
		wait(NULL);
	}
}

static void	get_stdin(int *fd, const char *end_flag)
{
	char	*line;

	close(fd[READ]);
	while (ft_strncmp(line, end_flag, ft_strlen(end_flag)))
	{
		line = get_next_line(0);
		write(fd[WRITE], line, ft_strlen(line));
		free(line);
	}
	free(line);
	exit(EXIT_SUCCESS);
}

static void	child_process(int argc, char **argv, char **envp, int cmd_idx)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit_with_error();
	pid = fork();
	if (pid == -1)
		exit_with_error();
	if (!pid)
	{
		close(fd[READ]);
		dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[WRITE]);
		set_fd(argc, argv, cmd_idx);
		execute(argv, envp, cmd_idx);
	}
	else
	{
		close(fd[WRITE]);
		dup2(fd[READ], STDIN_FILENO);
		close(fd[READ]);
		if (cmd_idx < argc - 2)
			child_process(argc, argv, envp, cmd_idx + 1);
		waitpid(pid, NULL, 0);
	}
}

static void	set_fd(int argc, char **argv, int cmd_idx)
{
	int	fd;

	fd = 0;
	if (cmd_idx == 2)
		fd = open_file(argv[1], FILE_IN);
	else if (cmd_idx == argc - 2)
		fd = open_file(argv[argc - 1], FILE_OUT);
	if (cmd_idx == 2 && fd != -1)
		dup2(fd, STDIN_FILENO);
	else if (cmd_idx == argc - 2 && fd != -1)
		dup2(fd, STDOUT_FILENO);
	close(fd);
	return ;
}
