/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:12:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/11 17:05:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t sz_)
{
	void	*res;

	// sz_ * count => overflow
	if (sz_ && (SIZE_MAX <= count || SIZE_MAX <= sz_ || SIZE_MAX / sz_ <= count))
		return (0);
	res = malloc(sz_ * count);
	if (!res)
		return (0);
	ft_bzero(res, (sz_ * count));
	return (res);
}
