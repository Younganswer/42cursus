/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:16:27 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/24 00:55:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, str, len + 1);
	return (res);
}
