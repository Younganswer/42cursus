/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 02:17:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/05 21:26:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/incs/libft.h"

int	ft_print_nbr(const int nbr)
{
	char	*num;
	int		printed;

	num = ft_itoa(nbr);
	if (!num)
		return (0);
	printed = ft_print_str(num);
	free(num);
	return (printed);
}
