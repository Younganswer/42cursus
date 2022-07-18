/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 02:24:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/18 15:11:51 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

int				ft_print_unsigned_int(unsigned int nbr);
static size_t	ft_num_len(unsigned int nbr);
static char		*ft_uitoa(unsigned int nbr);

int	ft_print_unsigned_int(unsigned int nbr)
{
	char	*num;
	int		printed;

	num = ft_uitoa(nbr);
	printed = ft_print_str(num);
	free(num);
	return (printed);
}

static size_t	ft_num_len(unsigned int nbr)
{
	size_t	len;

	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int nbr)
{
	char	*ret;
	size_t	len;

	len = ft_num_len(nbr);
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len--] = '\0';
	while (nbr)
	{
		ret[len--] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (ret);
}
