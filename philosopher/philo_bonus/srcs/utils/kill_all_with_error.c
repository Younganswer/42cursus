/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:09:41 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/01 20:51:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"

void	kill_all_with_error(const char *str, sem_t *print_sem)
{
	sem_wait(print_sem);
	ft_putstr_fd("\033[31mError\033[0m\n", 2);
	if (str)
	{
		ft_putstr_fd("\033[31m", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\033[0m\n", 2);
	}
	kill(0, SIGKILL);
	return ;
}
