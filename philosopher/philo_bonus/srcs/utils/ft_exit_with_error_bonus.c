/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_with_error_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:15:47 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/02 00:18:09 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils_bonus.h"

void	ft_exit_with_error(const char *str, int exit_flag)
{
	ft_putstr_fd("\033[31mError\033[0m\n", 2);
	if (str)
	{
		ft_putstr_fd("\033[31m", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\033[0m\n", 2);
	}
	exit(exit_flag);
}
