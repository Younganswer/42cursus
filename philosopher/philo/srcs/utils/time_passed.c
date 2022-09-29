/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_passed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:55:42 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/29 16:57:26 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"

t_bool	time_passed(size_t msec);

t_bool	time_passed(size_t msec)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	usleep(msec * 800);
	while (diff_time(&cur) < msec)
		usleep(msec * 200);
	return (TRUE);
}
