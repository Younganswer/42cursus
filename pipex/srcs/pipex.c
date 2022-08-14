/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:27:56 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/13 18:34:42 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	child_process(char **argv, char **envp, int *fd);
static void	parent_process(char **argv, char **envp, int *fd);

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		exit_with_error("\033[31mError: Invalid arguments\033[0m\nUsage: ./pipex [file1] [cmd1] [cmd2] [file2]\n");
	if (pipe(fd) == -1)
		exit_with_error("\033[31mError: Pipe error\033[0m\n");
	pid = fork();
	if (pid == -1)
		exit_with_error("\033[31mError: Fork error\033[0m\n");
	if (!pid)
		child_process(argv, envp, fd);
	waitpid(pid, NULL, 0);
	parent_process(argv, envp, fd);
	return (0);
}

static void	child_process(char **argv, char **envp, int *fd)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY, 0777);
	if (file_in == -1)
		exit_with_error("\033[31mError: Fail to open file\033[0m\n");
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
	return ;
}

static void	parent_process(char **argv, char **envp, int *fd)
{
	int	file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_out == -1)
		exit_with_error("\033[31mError: Fail to open file\033[0m\n");
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
	return ;
}