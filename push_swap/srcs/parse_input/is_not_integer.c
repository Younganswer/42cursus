/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:53:47 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 16:57:42 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parse_input.h"

t_bool	is_not_integer(const char *input)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(input);
	i = 0;
	while (i < len)
	{
		if (input[i] == ' ' || input[i] == '+' || input[i] == '-')
		{
			i++;
			continue ;
		}
		if (input[i] < '0' || '9' < input[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}
