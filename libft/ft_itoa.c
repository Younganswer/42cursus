/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:38:27 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/08 15:44:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n);
static size_t	get_num_len(long nbr);

char	*ft_itoa(int n)
{
	char	*res;
	long	nbr;
	size_t	len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	len += get_num_len(nbr);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res += len;
	*res-- = '\0';
	while (nbr)
	{
		*res-- = nbr % 10;
		nbr /= 10;
	}
	if (n < 0)
		*res-- = '-';
	return (res);
}

static size_t	get_num_len(long nbr)
{
	size_t	len;

	len = 0;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
