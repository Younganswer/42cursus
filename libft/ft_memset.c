/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:02:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/05 00:04:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	src;
	size_t			i;

	tmp = dest;
	src = c;
	i = 0;
	while (i++ < n)
		*tmp++ = src;
	return (dest);
}
