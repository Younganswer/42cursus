/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_time_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:04:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/02 00:18:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils_bonus.h"
#include <stdio.h>

size_t	diff_time(struct timeval *tv);

size_t	diff_time(struct timeval *tv)
{
	struct timeval	cur;
	size_t			ret;

	gettimeofday(&cur, NULL);
	ret = (cur.tv_sec - tv->tv_sec) * 1000;
	ret += (cur.tv_usec - tv->tv_usec) / 1000;
	return (ret);
}
