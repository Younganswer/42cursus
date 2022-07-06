/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:33:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/06 17:27:52 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	target;
	char	*tmp;
	char	*res;

	target = (char) c;
	tmp = (char *) s;
	res = 0;
	while (*tmp)
	{
		if (*tmp == target)
			res = tmp;
		tmp++;
	}
	if (*tmp == target)
		res = tmp;
	if (res)
		return (res);
	return (0);
}
