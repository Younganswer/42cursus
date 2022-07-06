/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:19:53 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/06 16:39:27 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;
	char	*tmp;

	target = (char) c;
	tmp = (char *) s;
	while (*tmp)
	{
		if (*tmp == target)
			return (tmp);
		tmp++;
	}
	if (*tmp == target)
		return (tmp);
	return (0);
}
