/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:07:18 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/05 00:10:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;
	size_t			i;

	if (!dest && !src)
		return (0);
	dest_tmp = dest;
	src_tmp = src;
	i = 0;
	while (i++ < n)
		*dest_tmp++ = *src_tmp++;
	return (dest);
}
