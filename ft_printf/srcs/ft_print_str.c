/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:54:49 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/15 02:34:00 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

int	ft_print_str(const char *str)
{
	int	printed;

	printed = 0;
	while (str[printed])
		printed += ft_print_char(str[printed]);
	return (printed);
}
