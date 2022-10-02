/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:48:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/02 16:01:25 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/routine_bonus.h"

void			*routine(void *arg);
static t_bool	p_take_forks(t_philo *const philo);
static t_bool	p_eat(t_philo *const philo);
static t_bool	p_sleep(t_philo *const philo);

void	*routine(void *arg)
{
	t_philo *const	philo = (t_philo *) arg;

	while (TRUE)
	{
		p_take_forks(philo);
		while (philo->info->num_of_philo == 1)
			usleep(1000);
		if (!p_eat(philo))
			break ;
		p_sleep(philo);
	}
	return (NULL);
}

static t_bool	p_take_forks(t_philo *const philo)
{
	sem_wait(philo->info->forks);
	sem_wait(philo->info->print_sem);
	printf("%zu %zu has taken a fork\n", \
		diff_time(philo->info->started), philo->id);
	sem_post(philo->info->print_sem);
	sem_wait(philo->info->forks);
	sem_wait(philo->info->print_sem);
	printf("%zu %zu has taken a fork\n", \
		diff_time(philo->info->started), philo->id);
	sem_post(philo->info->print_sem);
	return (TRUE);
}

static t_bool	p_eat(t_philo *const philo)
{
	sem_wait(philo->info->print_sem);
	gettimeofday(philo->last_eat, NULL);
	printf("%zu %zu is eating\n", diff_time(philo->info->started), philo->id);
	philo->num_of_eat++;
	sem_post(philo->info->print_sem);
	time_passed(philo->info->time_to_eat);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	return (TRUE);
}

static t_bool	p_sleep(t_philo *const philo)
{
	sem_wait(philo->info->print_sem);
	printf("%zu %zu is sleeping\n", diff_time(philo->info->started), philo->id);
	sem_post(philo->info->print_sem);
	time_passed(philo->info->time_to_sleep);
	sem_wait(philo->info->print_sem);
	printf("%zu %zu is thinking\n", diff_time(philo->info->started), philo->id);
	sem_post(philo->info->print_sem);
	return (TRUE);
}
