/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:48:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/29 16:18:31 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/behavior.h"

void			*behavior(void *arg);
static t_bool	p_take_forks(t_philo *const philo);
static t_bool	p_eat(t_philo *const philo);
static t_bool	p_sleep(t_philo *const philo);

void	*behavior(void *arg)
{
	t_philo *const	philo = (t_philo *) arg;

	while (!philo->info->started)
		continue ;
	while (!philo->info->someone_die)
	{
		if (philo->id % 2)
		{
			usleep(philo->info->num_of_philo * 2);
			p_take_forks(philo);
		}
		else
			p_take_forks(philo);
		if (!p_eat(philo))
			break ;
		if (!p_sleep(philo))
			break ;
	}
	return (NULL);
}

static t_bool	p_take_forks(t_philo *const philo)
{
	const size_t	left = philo->id;
	const size_t	right = (philo->id + 1) % philo->info->num_of_philo;
	t_fork *const	forks = philo->info->forks;

	if (philo->info->someone_die)
		return (FALSE);
	while (forks[left].state == OCCUPIED || forks[right].state == OCCUPIED)
		continue ;
	if (philo->info->someone_die)
		return (FALSE);
	philo->left_fork = &forks[left];
	forks[left].state = OCCUPIED;
	philo->right_fork = &forks[right];
	forks[right].state = OCCUPIED;
	printf("%zu %zu has taken a fork\n", diff_time(philo->info->started), philo->id);
	return (TRUE);
}

static t_bool	p_eat(t_philo *const philo)
{
	if (philo->info->someone_die)
		return (FALSE);
	gettimeofday(philo->last_eat, NULL);
	printf("%zu %zu is eating\n", diff_time(philo->info->started), philo->id);
	usleep(philo->info->time_to_eat);
	philo->left_fork->state = AVAILABLE;
	philo->right_fork->state = AVAILABLE;
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	return (TRUE);
}

static t_bool	p_sleep(t_philo *const philo)
{
	if (philo->info->someone_die)
		return (FALSE);
	printf("%zu %zu is sleeping\n", diff_time(philo->info->started), philo->id);
	usleep(philo->info->time_to_sleep);
	return (TRUE);
}
