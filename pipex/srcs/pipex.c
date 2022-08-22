/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   pipex_bonus.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: younhwan <younhwan@student.42seoul.kr> +#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2022/08/19 14:57:34 by younhwan  #+##+# */
/*   Updated: 2022/08/20 10:14:20 by younhwan ###   ########.fr   */
/**/
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	here_doc(int argc, const char *end_flag);
static void	get_stdin(int *fd, const char *end_flag);
static void	child_process(int argc, char **argv, char **envp, int cmd_idx);

int	main(int argc, char **argv, char **envp)
{
	int	cmd_idx;
	int	file_in;

	if (argc < 5)
		usage();
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		cmd_idx = 3;
		here_doc(argc, argv[2]);
	}
	else
	{
		cmd_idx = 2;
		file_in = open_file(argv[1], FILE_IN);
		if (file_in != -1)
			dup2(file_in, STDIN_FILENO);
	}
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
	}
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
		if (cmd_idx == argc - 2)
			dup2(open_file(argv[argc - 1], FILE_OUT), STDOUT_FILENO);
		execute(argv, envp, cmd_idx);
	}
	else
	{
		close(fd[WRITE]);
		dup2(fd[READ], STDIN_FILENO);
		if (cmd_idx < argc - 2)
			child_process(argc, argv, envp, cmd_idx + 1);
	}
}
