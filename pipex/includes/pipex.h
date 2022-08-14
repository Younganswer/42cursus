/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:03:44 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/13 18:17:42 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/libft/includes/libft.h"
# include "../libs/get_next_line/includes/get_next_line.h"

# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

// pipex_utils.c
void	exit_with_error(const char *str);
void	execute(char *file, char **envp);

#endif