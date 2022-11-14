/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_passed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:55:42 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/14 16:42:43 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"
#include <stdio.h>

t_bool	time_passed(int msec)
{
	struct timeval	start;
	struct timeval	cur;
	int				have_to_sleep;

	gettimeofday(&start, NULL);
	usleep(msec * 800);
	gettimeofday(&cur, NULL);
	have_to_sleep = msec * 1000 - ((cur.tv_sec - start.tv_sec) * \
		1000 * 1000 + (cur.tv_usec - start.tv_usec));
	while (200 < have_to_sleep)
	{
		usleep(200);
		gettimeofday(&cur, NULL);
		have_to_sleep = msec * 1000 - ((cur.tv_sec - start.tv_sec) * \
			1000 * 1000 + (cur.tv_usec - start.tv_usec));
	}
	usleep(200);
	return (TRUE);
}
