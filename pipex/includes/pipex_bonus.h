/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:03:44 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/19 16:07:17 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libs/libft/includes/libft.h"
# include "../libs/get_next_line/includes/get_next_line.h"

# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef enum e_fd_flag
{
	READ = 0,
	WRITE = 1,
}	t_fd_flag;

typedef enum e_open_flag
{
	HERE_DOC = 0,
	FILE_IN = 1,
	FILE_OUT = 2,
}	t_open_flag;

// pipex_utils_bonus.c
void		execute(const char *file, char **envp);
int			open_file(const char *file, t_open_flag flag);
void		exit_with_error(const char *str);
void		usage(void);

#endif