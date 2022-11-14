/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:45:39 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/14 15:16:52 by younhwan         ###   ########.fr       */
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
	gettimeofday(philos[0].info->started, NULL);
	while (TRUE)
	{
		if (eat_enough(philos))
			break ;
		if (someone_is_dead(philos))
			break ;
		usleep(philos->info->num_of_philo * 20);
	}
	return (TRUE);
}

static t_bool	someone_is_dead(t_philo *philos)
{
	int	i;

	i = -1;
	while ((size_t)++i < philos->info->num_of_philo)
	{
		if (philos[i].last_eat->tv_usec && \
			philos->info->time_to_die < diff_time(philos[i].last_eat))
		{
			pthread_mutex_lock(philos->info->print_mutex);
			printf("%zu %zu died\n", \
				diff_time(philos->info->started), philos[i].id);
			philos->info->someone_is_dead = TRUE;
			pthread_mutex_unlock(philos->info->print_mutex);
			return (TRUE);
		}
	}
	return (FALSE);
}

static t_bool	eat_enough(t_philo *philos)
{
	if (!philos->info->num_to_eat)
		return (FALSE);
	return (philos->info->num_of_philo == philos->info->num_of_philo_eat);
}
