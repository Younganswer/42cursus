/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:19:53 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/24 00:55:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;

	target = (char) c;
	while (*s)
	{
		if (*s == target)
			return ((char *) s);
		s++;
	}
	if (*s == target)
		return ((char *) s);
	return (0);
}
