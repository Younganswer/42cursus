/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:12:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/24 00:55:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_calloc(size_t count, size_t sz_);
static int	is_invalid_input(size_t count, size_t sz_);

void	*ft_calloc(size_t count, size_t sz_)
{
	void	*res;

	if (is_invalid_input(count, sz_))
		return (0);
	res = malloc(sz_ * count);
	if (!res)
		return (0);
	ft_bzero(res, (sz_ * count));
	return (res);
}

static int	is_invalid_input(size_t count, size_t sz_)
{
	if (SIZE_MAX <= count || SIZE_MAX <= sz_)
		return (1);
	if (sz_ && SIZE_MAX / sz_ <= count)
		return (1);
	return (0);
}
