/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:48:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/30 18:51:52 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/behavior.h"

void			*behavior(void *arg);
static t_bool	p_take_left_fork(t_philo *const philo);
static t_bool	p_take_right_fork(t_philo *const philo);
static t_bool	p_eat(t_philo *const philo);
static t_bool	p_sleep(t_philo *const philo);

void	*behavior(void *arg)
{
	t_philo *const	philo = (t_philo *) arg;

	while (!philo->info->started)
		continue ;
	while (!philo->info->someone_is_dead)
	{
		if (philo->id % 2)
		{
			usleep(philo->info->time_to_eat * 4);
			if (!p_take_right_fork(philo) && !p_take_left_fork(philo))
				break ;
		}
		else if (!p_take_left_fork(philo) && !p_take_right_fork(philo))
			break ;
		if (!p_eat(philo))
			break ;
		if (!p_sleep(philo))
			break ;
	}
	return (NULL);
}

static t_bool	p_take_left_fork(t_philo *const philo)
{
	const size_t	left = (philo->id + 1) % philo->info->num_of_philo;
	t_fork *const	fork = philo->info->forks;

	pthread_mutex_lock(fork[left].mutex);
	philo->left_fork = &fork[left];
	fork[left].state = OCCUPIED;
	if (philo->info->someone_is_dead)
	{
		pthread_mutex_unlock(fork[left].mutex);
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	p_take_right_fork(t_philo *const philo)
{
	const size_t	right = philo->id;
	t_fork *const	fork = philo->info->forks;

	pthread_mutex_lock(fork[right].mutex);
	philo->right_fork = &fork[right];
	fork[right].state = OCCUPIED;
	pthread_mutex_lock(philo->info->print_mutex);
	if (philo->info->someone_is_dead)
	{
		pthread_mutex_unlock(fork[right].mutex);
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	p_eat(t_philo *const philo)
{
	pthread_mutex_lock(philo->info->print_mutex);
	printf("%zu %zu has taken a fork\n", \
		diff_time(philo->info->started), philo->id);
	gettimeofday(philo->last_eat, NULL);
	printf("%zu %zu is eating\n", diff_time(philo->info->started), philo->id);
	pthread_mutex_unlock(philo->info->print_mutex);
	time_passed(philo->info->time_to_eat);
	philo->left_fork->state = AVAILABLE;
	philo->right_fork->state = AVAILABLE;
	pthread_mutex_unlock(philo->left_fork->mutex);
	pthread_mutex_unlock(philo->right_fork->mutex);
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	pthread_mutex_lock(philo->info->print_mutex);
	if (philo->info->someone_is_dead)
	{
		pthread_mutex_unlock(philo->info->print_mutex);
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	p_sleep(t_philo *const philo)
{
	printf("%zu %zu is sleeping\n", diff_time(philo->info->started), philo->id);
	pthread_mutex_unlock(philo->info->print_mutex);
	time_passed(philo->info->time_to_sleep);
	pthread_mutex_lock(philo->info->print_mutex);
	if (philo->info->someone_is_dead)
	{
		pthread_mutex_unlock(philo->info->print_mutex);
		return (FALSE);
	}
	printf("%zu %zu is thinking\n", diff_time(philo->info->started), philo->id);
	pthread_mutex_unlock(philo->info->print_mutex);
	return (TRUE);
}
