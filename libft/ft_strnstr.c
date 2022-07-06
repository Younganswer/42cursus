/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:27:05 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/06 19:28:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *target, size_t n)
{
	size_t	s_len;
	size_t	target_len;
	size_t	i;

	if (!(*target))
		return ((char *) s);
	s_len = ft_strlen(s);
	target_len = ft_strlen(target);
	if (s_len < target_len || n < target_len)
		return (0);
	i = 0;
	while (i + n <= s_len)
	{
		if (!ft_memcmp(s, target, target_len))
			return ((char *) s);
		s++;
	}
	return (0);
}
