/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:04:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/01 19:12:22 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"

size_t	diff_time(struct timeval *tv)
{
	struct timeval	cur;
	size_t			ret;

	gettimeofday(&cur, NULL);
	ret = (cur.tv_sec - tv->tv_sec) * 1000;
	ret += (cur.tv_usec - tv->tv_usec) / 1000;
	return (ret);
}
