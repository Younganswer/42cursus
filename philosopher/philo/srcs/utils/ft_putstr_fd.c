/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:26:53 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/25 15:27:56 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"

int	ft_putstr_fd(const char *str, int fd)
{
	int	printed;

	printed = 0;
	while (str && *str)
		printed += write(fd, str++, 1);
	return (printed);
}