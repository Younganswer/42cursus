/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:05:39 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/05 00:10:13 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = b;
	i = 0;
	while (i++ < n)
		*tmp++ = 0;
	return ;
}
