/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Crp_eated: 2022/09/28 10:48:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/28 12:48:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/behavior.h"

void			*behavior(void *arg);
static t_bool	p_take_forks(t_philo *const philo);
static t_bool	p_eat(t_philo *const philo);
static t_bool	p_sleep(t_philo *const philo);

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
	while (philo->info->forks[philo->id].state == OCCUPIED || \
			philo->info->forks[(philo->id + 1) % philo->info->num_of_philo].state == OCCUPIED)
		continue ;
	philo->left_fork = &philo->info->forks[philo->id];
	philo->info->forks[philo->id].state = OCCUPIED;
	philo->right_fork = &philo->info->forks[(philo->id + 1) % philo->info->num_of_philo];
	philo->info->forks[(philo->id + 1) % philo->info->num_of_philo].state = OCCUPIED;
	gettimeofday(philo->cur, NULL);
	printf("%d %zu has taken a fork\n", philo->cur->tv_usec - philo->info->started->tv_usec, philo->id);
	return (TRUE);
}

static t_bool	p_eat(t_philo *const philo)
{
	gettimeofday(philo->cur, NULL);
	if (philo->info->time_to_die < (size_t)philo->cur->tv_usec - philo->info->started->tv_usec)
		return (FALSE);
	printf("%d %zu is eating\n", philo->cur->tv_usec - philo->info->started->tv_usec, philo->id);
	usleep(philo->info->time_to_eat);
	philo->left_fork->state = AVAILABLE;
	philo->right_fork->state = AVAILABLE;
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	return (TRUE);
}

static t_bool	p_sleep(t_philo *const philo)
{
	gettimeofday(philo->cur, NULL);
	if (philo->info->time_to_die < (size_t)philo->cur->tv_usec - philo->info->started->tv_usec)
		return (FALSE);
	printf("%d %zu is sleeping\n", philo->cur->tv_usec - philo->info->started->tv_usec, philo->id);
	usleep(philo->info->time_to_sleep);
	return (TRUE);
}
