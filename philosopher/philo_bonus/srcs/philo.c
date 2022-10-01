/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:48:27 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/01 20:02:15 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static t_bool	start_routine(t_philo *philos);
static t_philo	*init_philos(int argc, char **argv);
static t_info	*init_info(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_philo	*philos;
	size_t	sz_;

	if (argc < 5 || 6 < argc)
		ft_exit_with_error("Usage: ./philo <number_of_philosophers> \
			<time_to_die> <time_to_eat> <time_to_sleep> \
			[number_of_times_each_phliosopher_must_eat]", 0);
	philos = init_philos(argc, argv);
	sz_ = philos[0].info->num_of_philo;
	start_routine(philos);
	sem_close(philos->info->forks);
	sem_close(philos->info->print_sem);
	return (0);
}

static t_bool	start_routine(t_philo *philos)
{
	pid_t	pid;
	size_t	i;

	i = 0;
	while (i < philos->info->num_of_philo)
	{
		pid = fork();
		i += 2;
	}
	i = 1;
	while (i < philos->info->num_of_philo)
	{
		pid = fork();
		i += 2;
	}
	if (pid == -1)
		kill_with_error("Fail to fork", philos->info->print_sem);
	if (!pid)
	{
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		monitor(&philos[i]);
		pthread_join(philos[i].thread, NULL);
	}
	else
		waitpid(pid, NULL, 0);
	return (TRUE);
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
		gettimeofday(ret[i].last_eat, NULL);
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
	if (argc == 6)
		ret->num_to_eat = ft_atoi(argv[5]);
	ret->forks = sem_open("forks_sem", O_CREAT, ret->num_of_philo);
	sem_unlink("forks_sem");
	ret->print_sem = sem_open("print_sem", O_CREAT, 1);
	sem_unlink("print_sem");
	ret->started = (struct timeval *) malloc(sizeof(struct timeval));
	if (ret->started)
		ft_exit_with_error("Fail to malloc at started", 1);
	gettimeofday(ret->started, NULL);
	return (ret);
}
