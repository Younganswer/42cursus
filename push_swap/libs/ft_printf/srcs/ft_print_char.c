/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:50:54 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/05 21:25:54 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/incs/libft.h"

int	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
