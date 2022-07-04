/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:11:23 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/05 00:15:03 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (dest == src || !n)
		return (dest);
	if (dest < src)
	{
		dest_tmp = (unsigned char *) dest;
		src_tmp = (unsigned char *) src;
		while (n--)
			*dest_tmp++ = *src_tmp++;
	}
	else
	{
		dest_tmp = (unsigned char *) dest + (n - 1);
		src_tmp = (unsigned char *) src + (n - 1);
		while (n--)
			*dest_tmp-- = *src_tmp--;
	}
	return (dest);
}