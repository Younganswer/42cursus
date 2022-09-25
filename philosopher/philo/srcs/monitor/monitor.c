/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:45:39 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/25 20:33:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/monitor.h"

t_bool	monitor(t_info *info);

t_bool	monitor(t_info *info)
{
	struct timeval	cur;
	size_t			i;

	gettimeofday(&cur, NULL);
	i = 0;
	while (i < info->num_of_philo)
	{
		printf("%d_in_ms %zu has taken a fork\n", info->philos[i].time_ate.tv_usec, info->philos[i].id);
		i++;
	}
	return (TRUE);
}
