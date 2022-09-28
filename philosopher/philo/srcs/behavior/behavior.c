/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:48:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/28 11:02:21 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/behavior.h"

void			*behavior(void *arg);
static t_bool	take_forks(t_philo *philo);
static t_bool	eat(t_philo *philo);
static t_bool	sleep(t_philo *philo);

void	*behavior(void *arg)
{
	t_philo	*const philo = (t_philo *) arg;

	while (!philo->info->started)
		continue ;
	while (!philo->info->someone_die)
	{
		if (philo->id % 2)
		{
			usleep(philo->info->num_of_philo * 2);
			take_forks(philo);
		}
		else
			take_forks(philo);
		if (!eat(philo))
			break ;
		if (!sleep(philo))
			break ;
	}
	return (NULL);
}
