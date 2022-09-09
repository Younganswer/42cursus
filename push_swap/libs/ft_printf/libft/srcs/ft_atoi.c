/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:53:11 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 17:56:55 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "limits.h"

int			ft_atoi(const char *str);

int	ft_atoi(const char *str)
{
	long long	ret;
	int			sign;
	size_t		i;

	ret = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign += -2 * (str[i] == '-');
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_exit_with_error(0, EXIT_SUCCESS);
		ret = 10 * ret + (str[i] - '0');
		if (ret < INT32_MIN || INT32_MAX < ret)
			ft_exit_with_error(0, EXIT_FAILURE);
		i++;
	}
	return ((int)(ret * sign));
}
