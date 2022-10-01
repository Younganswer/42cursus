/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:48:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/01 19:55:25 by younhwan         ###   ########.fr       */
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

	while (TRUE)
	{
		if (philo->info->num_of_philo == 1 && !usleep(1000))
			continue ;
		p_take_forks(philo);
		p_eat(philo);
		if (philo->num_of_eat == philo->info->num_to_eat && \
			!sem_post(philo->info->print_sem))
			break ;
		p_sleep(philo);
	}
	return (NULL);
}

static t_bool	p_take_forks(t_philo *const philo)
{
	sem_wait(philo->info->forks);
	sem_wait(philo->info->forks);
	sem_wait(philo->info->print_sem);
	printf("%zu %zu has taken a fork\n", \
		diff_time(philo->info->started), philo->id);
	return (TRUE);
}

static t_bool	p_eat(t_philo *const philo)
{
	gettimeofday(philo->last_eat, NULL);
	printf("%zu %zu is eating\n", diff_time(philo->info->started), philo->id);
	philo->num_of_eat++;
	sem_post(philo->info->print_sem);
	time_passed(philo->info->time_to_eat);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	if (philo->info->num_to_eat && \
		philo->num_of_eat == philo->info->num_to_eat)
		philo->info->num_of_philo_eat++;
	sem_wait(philo->info->print_sem);
	return (TRUE);
}

static t_bool	p_sleep(t_philo *const philo)
{
	printf("%zu %zu is sleeping\n", diff_time(philo->info->started), philo->id);
	sem_post(philo->info->print_sem);
	time_passed(philo->info->time_to_sleep);
	sem_wait(philo->info->print_sem);
	printf("%zu %zu is thinking\n", diff_time(philo->info->started), philo->id);
	sem_post(philo->info->print_sem);
	return (TRUE);
}
