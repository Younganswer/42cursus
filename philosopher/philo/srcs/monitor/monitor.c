/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:45:39 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/28 11:23:46 by younhwan         ###   ########.fr       */
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
	return (FALSE);
}

static t_bool	eat_enough(t_philo *philos)
{
	return (TRUE);
}
