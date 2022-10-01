/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:45:39 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/01 19:57:38 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"
#include "../../incs/monitor.h"

t_bool			monitor(t_philo *philos);
static void		when_someone_dies_kill_all(t_philo *philos);
static t_bool	eat_enough(t_philo *philos);

t_bool	monitor(t_philo *philos)
{
	
	while (TRUE)
	{
		if (0 < philos->info->num_to_eat && eat_enough(philos))
			break ;
		when_someone_dies_kill_all(philos);
		usleep(philos->info->num_of_philo * 20);
	}
	return (TRUE);
}

static void		when_someone_dies_kill_all(t_philo *philos)
{
	int	i;

	i = -1;
	while ((size_t)++i < philos->info->num_of_philo)
	{
		if (philos[i].last_eat->tv_usec && \
			philos->info->time_to_die < diff_time(philos[i].last_eat))
		{
			sem_wait(philos->info->print_sem);
			printf("%zu %zu died\n", \
				diff_time(philos->info->started), philos[i].id);
			kill(0, SIGKILL);
		}
	}
	return ;
}

static t_bool	eat_enough(t_philo *philos)
{
	if (philos->info->num_of_philo == philos->info->num_of_philo_eat)
		return (TRUE);
	return (FALSE);
}
