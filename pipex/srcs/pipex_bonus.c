/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:57:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/19 16:33:50 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void here_doc(int argc, const char *limiter);
static void child_process(const char *cmd, char **envp);

int main(int argc, char **argv, char **envp)
{
    int cmd_idx;
    int file_in;
    int file_out;

    if (argc < 5)
		usage();
    if (!ft_strncmp(argv[1], "here_doc", 8))
    {
        cmd_idx = 3;
        file_out = open_file(argv[argc - 1], HERE_DOC);
        here_doc(argc, argv[2]);
		while (TRUE)
			;
    }
    else
    {
        cmd_idx = 2;
        file_out = open_file(argv[argc - 1], FILE_OUT);
        file_in = open_file(argv[1], FILE_IN);
        dup2(file_in, STDIN_FILENO);
    }
    while (cmd_idx < argc - 2)
        child_process(argv[cmd_idx++], envp);
    dup2(file_out, STDOUT_FILENO);
    execute(argv[cmd_idx], envp);
    return (0);
}

static void here_doc(int argc, const char *end_flag)
{
    pid_t   reader;
    int     fd[2];
	char	*line;

	if (argc < 6)
		usage();
	if (pipe(fd) == -1)
		exit_with_error("\033[31mError: Pipe error\033[0m\n");
	reader = fork();
	if (!reader)
	{
		close(fd[READ]);
		while (TRUE)
		{
			line = get_next_line(0);
			if (!line)
				break ;
			if (!ft_strncmp(line, end_flag, ft_strlen(end_flag)))
				exit(EXIT_SUCCESS);
			write(fd[WRITE], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[WRITE]);
		dup2(fd[READ], STDIN_FILENO);
		wait(NULL);
	}
    return ;
}

static void child_process(const char *cmd, char **envp)
{
    pid_t   pid;
    int     fd[2];

    if (pipe(fd) == -1)
		exit_with_error("\033[31mError: Pipe error\033[0m\n");
    pid = fork();
	if (pid == -1)
		exit_with_error("\033[31mError: Fork error\033[0m\n");
    if (!pid)
    {
        close(fd[READ]);
        dup2(fd[WRITE], STDOUT_FILENO);
        execute(cmd, envp);
    }
    else
    {
        close(fd[WRITE]);
        dup2(fd[READ], STDIN_FILENO);
        waitpid(pid, NULL, 0);
    }
    return ;
}