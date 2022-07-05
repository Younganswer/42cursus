/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:19:53 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/06 00:26:54 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;
	int		i;

	target = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == target)
			return (&s[i]);
		i++;
	}
	if (s[i] == target)
		return (&s[i]);
	return (0);
}
