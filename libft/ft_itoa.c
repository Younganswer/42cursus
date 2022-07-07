/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:38:27 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/07 18:46:27 by younhwan         ###   ########.fr       */
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
	size_t	i;

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
	i = 0;
	if (n < 0)
		res[i++] = '-';
		
	while (i)
	{

	}
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