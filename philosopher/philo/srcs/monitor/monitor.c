/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:45:39 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/29 16:44:38 by younhwan         ###   ########.fr       */
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
		if (0 <= philos->info->num_to_eat && eat_enough(philos))
			break ;
		usleep(philos->info->num_of_philo);
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
			philos->info->someone_die = TRUE;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static t_bool	eat_enough(t_philo *philos)
{
	(void) philos;
	return (TRUE);
}
