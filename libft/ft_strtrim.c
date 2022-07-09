/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:10:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/09 13:44:46 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (0 < end && ft_strchr(set, s1[end]))
		end--;
	if (end < start || (!end && ft_strchr(set, s1[end])))
		return (ft_strdup(""));
	res = (char *) malloc(sizeof(char) * (end - start + 2));
	if (!res)
		return (0);
	ft_strlcpy(res, &s1[start], end - start + 2);
	return (res);
}
