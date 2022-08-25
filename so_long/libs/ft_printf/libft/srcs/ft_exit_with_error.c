/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_with_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:15:47 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/25 16:17:49 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_exit_with_error(const char *str)
{
	ft_putstr_fd("\033[31mError\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\033[0m\n", 2);
	exit(EXIT_FAILURE);
}
