/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:04:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/29 16:09:14 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"

size_t	diff_time(struct timeval *tv);

size_t	diff_time(struct timeval *tv)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return (cur.tv_usec - tv->tv_usec);
}
