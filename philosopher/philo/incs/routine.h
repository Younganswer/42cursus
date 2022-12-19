/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:47:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/29 16:05:51 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include <unistd.h>
# include <stdio.h>
# include "structs.h"
# include "utils.h"

# define FORK_MSG "%zu %zu has taken a fork\n"
# define EATING_MSG "%zu %zu is eating\n"
# define SLEEPING_MSG "%zu %zu is sleeping\n"
# define THINKING_MSG "%zu %zu is thinking\n"

// routine.c
void	*routine(void *arg);

#endif