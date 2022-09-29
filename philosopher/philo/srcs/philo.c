/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:48:27 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/29 17:06:46 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static t_philo	*init_philos(int argc, char **argv);
static t_info	*init_info(int argc, char **argv);
static t_fork	*init_forks(size_t sz_);

int	main(int argc, char **argv)
{
	t_philo	*philos;
	size_t	sz_;
	size_t	i;

	if (argc < 5 || 6 < argc)
		ft_exit_with_error("Usage: ./philo <number_of_philosophers> \
			<time_to_die> <time_to_eat> <time_to_sleep> \
			[number_of_times_each_phliosopher_must_eat]", 0);
	philos = init_philos(argc, argv);
	sz_ = philos[0].info->num_of_philo;
	i = 0;
	while (i < sz_)
	{
		pthread_create(&(philos[i].thread), NULL, behavior, &philos[i]);
		i++;
	}
	monitor(philos);
	i = 0;
	while (i < sz_)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (0);
}

static t_philo	*init_philos(int argc, char **argv)
{
	t_philo	*ret;
	t_info	*info;
	size_t	i;

	info = init_info(argc, argv);
	ret = (t_philo *) malloc(sizeof(t_philo) * info->num_of_philo);
	if (!ret)
		ft_exit_with_error("Fail to malloc at philos", 1);
	memset(ret, 0, sizeof(t_philo) * info->num_of_philo);
	i = 0;
	while (i < info->num_of_philo)
	{
		ret[i].id = i;
		ret[i].info = info;
		ret[i].last_eat = (struct timeval *) malloc(sizeof(struct timeval));
		if (!ret[i].last_eat)
			ft_exit_with_error("Fail to malloc at last_eat", 1);
		memset(ret[i].last_eat, 0, sizeof(struct timeval));
		i++;
	}
	return (ret);
}

static t_info	*init_info(int argc, char **argv)
{
	t_info	*ret;

	ret = (t_info *) malloc(sizeof(t_info));
	if (!ret)
		ft_exit_with_error("Fail to malloc at info", 1);
	memset(ret, 0, sizeof(t_info));
	ret->num_of_philo = ft_atoi(argv[1]);
	ret->time_to_die = ft_atoi(argv[2]);
	ret->time_to_eat = ft_atoi(argv[3]);
	ret->time_to_sleep = ft_atoi(argv[4]);
	ret->num_to_eat = -1;
	if (argc == 6)
		ret->num_to_eat = ft_atoi(argv[5]);
	ret->forks = init_forks(ret->num_of_philo);
	ret->someone_die = FALSE;
	return (ret);
}

static t_fork	*init_forks(size_t sz_)
{
	t_fork	*ret;
	size_t	i;

	ret = (t_fork *) malloc(sizeof(t_fork) * sz_);
	if (!ret)
		ft_exit_with_error("Fail to malloc at forks", 1);
	memset(ret, 0, sizeof(t_fork) * sz_);
	i = 0;
	while (i < sz_)
	{
		ret[i].mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
		if (!ret[i].mutex)
			ft_exit_with_error("Fail to malloc at mutex", 1);
		memset(ret[i].mutex, 0, sizeof(pthread_mutex_t));
		ret[i++].state = AVAILABLE;
	}
	return (ret);
}
