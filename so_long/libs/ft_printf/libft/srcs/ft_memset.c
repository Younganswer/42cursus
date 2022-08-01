/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:02:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/06 17:18:22 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	src;

	tmp = (unsigned char *) dest;
	src = (unsigned char) c;
	while (n--)
		*tmp++ = src;
	return (dest);
}
