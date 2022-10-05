/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:54:49 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/05 21:26:08 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/incs/libft.h"

int	ft_print_str(const char *str)
{
	int	printed;

	printed = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[printed])
		printed += ft_print_char(str[printed]);
	return (printed);
}
