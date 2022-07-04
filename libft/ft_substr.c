/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:56:43 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/04 19:05:37 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		idx;

	res = (char *) malloc(sizeof(char) * len);
	if (!res)
		return (0);
	idx = 0;
	while (start + idx < len - 1)
	{
		res[idx] = s[start + idx];
		idx++;
	}
	return (res);
}
