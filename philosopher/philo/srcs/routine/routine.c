/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:48:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/01 14:32:57 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/routine.h"

void			*routine(void *arg);
static t_bool	p_take_forks(t_philo *const philo);
static t_bool	p_eat(t_philo *const philo);
static t_bool	p_sleep(t_philo *const philo);

void	*routine(void *arg)
{
	t_philo *const	philo = (t_philo *) arg;

	while (!philo->info->started)
		continue ;
	if (philo->info->num_of_philo == 1)
		gettimeofday(philo->last_eat, NULL);
	while (!philo->info->someone_is_dead)
	{
		if (philo->info->num_of_philo == 1 && !usleep(1000))
			continue ;
		if (philo->id % 2 && !philo->last_eat->tv_usec)
			usleep(philo->info->time_to_eat * 5);
		if (!p_take_forks(philo))
			break ;
		if (!p_eat(philo))
			break ;
		if (!p_sleep(philo))
			break ;
		if (philo->info->num_to_eat && \
			philo->num_of_eat == philo->info->num_to_eat)
			break ;
	}
	return (NULL);
}

static t_bool	p_take_forks(t_philo *const philo)
{
	const size_t	left = (philo->id + 1) % philo->info->num_of_philo;
	const size_t	right = philo->id;
	t_fork *const	forks = philo->info->forks;

	pthread_mutex_lock(forks[left].mutex);
	pthread_mutex_lock(forks[right].mutex);
	pthread_mutex_lock(philo->info->print_mutex);
	if (philo->info->someone_is_dead)
	{
		pthread_mutex_unlock(forks[left].mutex);
		pthread_mutex_unlock(forks[right].mutex);
		pthread_mutex_unlock(philo->info->print_mutex);
		return (FALSE);
	}
	philo->left_fork = &forks[left];
	philo->right_fork = &forks[right];
	printf("%zu %zu has taken a fork\n", \
		diff_time(philo->info->started), philo->id);
	return (TRUE);
}

static t_bool	p_eat(t_philo *const philo)
{
	gettimeofday(philo->last_eat, NULL);
	printf("%zu %zu is eating\n", diff_time(philo->info->started), philo->id);
	philo->num_of_eat++;
	pthread_mutex_unlock(philo->info->print_mutex);
	time_passed(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->left_fork->mutex);
	pthread_mutex_unlock(philo->right_fork->mutex);
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	if (philo->info->num_to_eat && \
		philo->num_of_eat == philo->info->num_to_eat)
		philo->info->num_of_philo_eat++;
	if (philo->info->someone_is_dead)
		return (FALSE);
	pthread_mutex_lock(philo->info->print_mutex);
	return (TRUE);
}

static t_bool	p_sleep(t_philo *const philo)
{
	if (philo->info->someone_is_dead)
		return (pthread_mutex_unlock(philo->info->print_mutex));
	printf("%zu %zu is sleeping\n", diff_time(philo->info->started), philo->id);
	pthread_mutex_unlock(philo->info->print_mutex);
	time_passed(philo->info->time_to_sleep);
	if (philo->info->someone_is_dead)
		return (FALSE);
	pthread_mutex_lock(philo->info->print_mutex);
	if (philo->info->someone_is_dead)
		return (pthread_mutex_unlock(philo->info->print_mutex));
	printf("%zu %zu is thinking\n", diff_time(philo->info->started), philo->id);
	pthread_mutex_unlock(philo->info->print_mutex);
	return (TRUE);
}
