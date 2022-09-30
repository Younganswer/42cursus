/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:45:39 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/30 18:37:27 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"
#include "../../incs/monitor.h"

t_bool			monitor(t_philo *philos);
static t_bool	someone_is_dead(t_philo *philos);
static t_bool	eat_enough(t_philo *philos);

t_bool	monitor(t_philo *philos)
{
	philos[0].info->started = (struct timeval *) malloc(sizeof(struct timeval));
	if (!philos[0].info->started)
		ft_exit_with_error("Fail to malloc at started", 1);
	gettimeofday(philos[0].info->started, 0);
	while (TRUE)
	{
		if (someone_is_dead(philos))
			break ;
		if (0 < philos->info->num_to_eat && eat_enough(philos))
			break ;
		usleep(philos->info->num_of_philo * 20);
	}
	return (TRUE);
}

static t_bool	someone_is_dead(t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < philos->info->num_of_philo)
	{
		if (0 < diff_time(philos->info->started) && \
			philos->info->time_to_die < diff_time(philos[i].last_eat))
		{
			pthread_mutex_lock(philos->info->print_mutex);
			printf("%zu %zu died\n", \
				diff_time(philos->info->started), philos[i].id);
			philos->info->someone_is_dead = TRUE;
			pthread_mutex_unlock(philos->info->print_mutex);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static t_bool	eat_enough(t_philo *philos)
{
	(void) philos;
	return (FALSE);
}
