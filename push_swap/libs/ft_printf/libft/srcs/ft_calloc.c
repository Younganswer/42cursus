/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:12:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/12/19 14:02:27 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void			*ft_calloc(size_t sz_, size_t count, const char *error_msg);
static t_bool	is_invalid_input(size_t sz_, size_t count);

void	*ft_calloc(size_t sz_, size_t count, const char *error_msg)
{
	void	*res;

	if (is_invalid_input(count, sz_))
		ft_exit_with_error(error_msg, 1);
	res = malloc(sz_ * count);
	if (!res)
		ft_exit_with_error(error_msg, 1);
	ft_bzero(res, (sz_ * count));
	return (res);
}

static t_bool	is_invalid_input(size_t sz_, size_t count)
{
	if (SIZE_MAX <= sz_ || SIZE_MAX <= count)
		return (TRUE);
	if (sz_ && SIZE_MAX / sz_ <= count)
		return (TRUE);
	return (FALSE);
}
