/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:28:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/05 17:47:20 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t sz_)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (!sz_)
		return (src_len);
	i = 0;
	while (src[i] && i < (sz_ - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
