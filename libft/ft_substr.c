/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:00:00 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/10 21:27:00 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = (size_t) ft_strlen(s);
	if ((unsigned int) s_len < start)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, &s[start], len + 1);
	return (res);
}
