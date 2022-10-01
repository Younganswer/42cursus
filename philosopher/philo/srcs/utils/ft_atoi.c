/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:53:11 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/01 11:48:10 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/utils.h"
#include "limits.h"

int			ft_atoi(const char *str);
static int	ft_isspace(const char c);

int	ft_atoi(const char *str)
{
	unsigned long long	nbr;
	int					i;

	nbr = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			ft_exit_with_error("Input must be natural number", 0);
		i++;
	}
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		if (str[i] < '0' || '9' < str[i])
			ft_exit_with_error("Input must be integer", 0);
		nbr = 10 * nbr + (str[i] - '0');
		if (2147483647 < nbr)
			ft_exit_with_error("Input must be integer", 0);
		i++;
	}
	if (str[i])
		ft_exit_with_error("Input must be integer", 0);
	if (!nbr)
		ft_exit_with_error("Input must be natural number", 0);
	return ((int) nbr);
}

static int	ft_isspace(const char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}
