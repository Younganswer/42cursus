/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:53:06 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/03 15:34:18 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stddef.h>
# include <sys/time.h>

typedef enum ebool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef struct s_info
{
	size_t			num_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			num_to_eat;
	size_t			num_of_philo_eat;
	sem_t			*forks;
	struct timeval	*started;
	sem_t			*print_sem;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	size_t			id;
	size_t			num_of_eat;
	pthread_t		thread;
	struct timeval	*last_eat;
}	t_philo;

#endif