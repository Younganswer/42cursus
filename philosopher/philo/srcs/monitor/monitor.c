/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:45:39 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/26 11:28:50 by younhwan         ###   ########.fr       */
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
		i++;
	}
	return (TRUE);
}
