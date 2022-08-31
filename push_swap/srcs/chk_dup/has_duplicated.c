/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:48:59 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/01 00:02:19 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/chk_dup.h"

t_bool	has_duplicated(int *arr);

t_bool	has_duplicated(int *arr)
{
	int	sz_;
	int	i;

	sz_ = sizeof(arr) / sizeof(*arr);
	i = 0;
	while (i < sz_ - 1)
	{
		if (arr[i] == arr[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
