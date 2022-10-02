/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:45:39 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/02 15:04:03 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils_bonus.h"
#include "../../incs/monitor_bonus.h"

t_bool			monitor(t_philo *philo);
static void		when_i_die_kill_all(t_philo *philo);
static t_bool	eat_enough(t_philo *philo);

t_bool	monitor(t_philo *philo)
{
	while (!eat_enough(philo))
	{
		when_i_die_kill_all(philo);
		usleep(philo->info->num_of_philo * 20);
	}
	return (TRUE);
}

static void	when_i_die_kill_all(t_philo *philo)
{
	if (philo->last_eat->tv_usec && \
		philo->info->time_to_die < diff_time(philo->last_eat))
	{
		sem_wait(philo->info->print_sem);
		printf("%zu %zu died\n", \
			diff_time(philo->info->started), philo->id);
		kill(0, SIGKILL);
	}
	return ;
}

static t_bool	eat_enough(t_philo *philo)
{
	if (!philo->info->num_to_eat)
		return (FALSE);
	return (philo->num_of_eat == philo->info->num_to_eat);
}
