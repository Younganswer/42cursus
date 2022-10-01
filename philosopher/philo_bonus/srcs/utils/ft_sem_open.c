/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:59:33 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/02 00:01:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"

sem_t	*ft_sem_open(const char *name, int value)
{
	sem_t	*ret;

	sem_unlink(name);
	ret = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (ret == SEM_FAILED)
		ft_exit_with_error("Fail to open semaphore", 1);
	return (ret);
}
