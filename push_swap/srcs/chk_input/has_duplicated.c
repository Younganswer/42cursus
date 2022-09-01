/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:48:59 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/01 13:33:03 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/chk_input.h"

t_bool	has_duplicated(int *arr, int n);

t_bool	has_duplicated(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] == arr[i + 1])
			return (TRUE);
		i++;
	}
	return (FALSE);
}
