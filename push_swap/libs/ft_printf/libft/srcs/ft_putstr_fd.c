/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:52:37 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/16 20:13:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr_fd(const char *s, int fd)
{
	int	printed;

	printed = 0;
	while (s && *s)
		printed += ft_putchar_fd(*s++, fd);
	return (printed);
}
