/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:48:27 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/25 15:34:42 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static t_info	*init_info(int argc, char **argv);
static t_philo	*init_philo(size_t sz_);

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc < 5 || 6 < argc)
		ft_exit_with_error("Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_phliosopher_must_eat]", 0);
	info = init_info(argc, argv);
	return (0);
}

static t_info	*init_info(int argc, char **argv)
{
	t_info	*ret;

	ret = (t_info *) malloc(sizeof(t_info));
	if (!ret)
		exit(EXIT_FAILURE);
	memset(ret, 0, sizeof(t_info));
	ret->num_of_philo = ft_atoi(argv[1]);
	ret->time_to_die = ft_atoi(argv[2]);
	ret->time_to_eat = ft_atoi(argv[3]);
	ret->time_to_sleep = ft_atoi(argv[4]);
	ret->num_to_eat = -1;
	if (argc == 6)
		ret->num_to_eat = ft_atoi(argv[5]);
	ret->philos = init_philo(ret->num_of_philo);
	return (ret);
}

static t_philo	*init_philo(size_t sz_)
{
	t_philo	*ret;
	size_t	i;

	ret = (t_philo *) malloc(sizeof(t_philo) * sz_);
	if (!ret)
		exit(EXIT_FAILURE);
	memset(ret, 0, sizeof(t_philo) * sz_);
	i = 0;
	while (i < sz_)
	{
		ret[i].id = i;
		i++;
	}
	return (ret);
}
