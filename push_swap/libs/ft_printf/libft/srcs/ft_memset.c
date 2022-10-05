/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:02:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/05 17:47:20 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

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
