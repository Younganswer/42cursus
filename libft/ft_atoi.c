/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:53:11 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/14 12:28:21 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

int			ft_atoi(const char *str);
static int	ft_isspace(char c);

int	ft_atoi(const char *str)
{
	unsigned long long	nbr;
	int					sign;
	size_t				i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		nbr = 10 * nbr + (str[i] - '0');
		if (__LONG_LONG_MAX__ < nbr)
			return (-1);
		if (sign == -1 && (unsigned long long) __LONG_LONG_MAX__ + 1 < nbr)
			return (0);
		i++;
	}
	return ((int) nbr * sign);
}

static int	ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}
