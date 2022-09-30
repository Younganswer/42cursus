/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:53:06 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/30 17:58:03 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include <stddef.h>
# include <sys/time.h>

typedef enum ebool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef enum e_state
{
	OCCUPIED = 0,
	AVAILABLE = 1,
}	t_state;

typedef struct s_fork
{
	pthread_mutex_t	*mutex;
	t_state			state;
}	t_fork;

typedef struct s_info
{
	size_t			num_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			num_to_eat;
	t_fork			*forks;
	struct timeval	*started;
	t_bool			someone_is_dead;
	pthread_mutex_t	*print_mutex;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	t_fork			*left_fork;
	t_fork			*right_fork;
	size_t			id;
	pthread_t		thread;
	struct timeval	*last_eat;
}	t_philo;

#endif