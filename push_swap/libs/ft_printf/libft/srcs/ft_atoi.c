/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:53:11 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/31 23:27:09 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "limits.h"

int			ft_atoi(const char *str);
static int	ft_isspace(char c);

int	ft_atoi(const char *str)
{
	long long	ret;
	int			sign;
	size_t		i;

	ret = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign += -2 * (str[i] == '-');
		i++;
	}
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		ret = 10 * ret + (str[i] - '0');
		if (ret < INT32_MIN || INT32_MAX < ret)
			ft_exit_with_error(0);	
		i++;
	}
	return ((int) (ret * sign));
}

static int	ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}
