/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:50:51 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/01 19:25:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <signal.h>
# include <semaphore.h>
# include "structs.h"

// ft_atoi.c
int		ft_atoi(const char *str);

// ft_exit_with_error.c
void	ft_exit_with_error(const char *str, int exit_flag);

// ft_putstr_fd.c
int		ft_putstr_fd(const char *str, int fd);

// kill_with_error.c
void	kill_with_error(const char *str, sem_t *print_sem);

// diff_time.c
size_t	diff_time(struct timeval *tv);

// time_passed.c
t_bool	time_passed(int msec);

#endif