/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:45:39 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/26 12:31:30 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/monitor.h"

t_bool	monitor(t_philo *philos);

t_bool	monitor(t_philo *philos)
{
	struct timeval	*cur;

	cur = NULL;
	while (TRUE)
	{
		gettimeofday(cur, NULL);
		if (5000 < cur->tv_usec - philos[0].info->started->tv_usec)
			break ;
	}
	return (TRUE);
}
