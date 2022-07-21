/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:58:38 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/22 00:55:16 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c);
void	ft_strlcat(char **dest, const char *src);
char	*ft_strndup(const char *src, size_t n);
void	ft_strncpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	str_len;

	if (!str)
		return (0);
	i = 0;
	str_len = ft_strlen(str);
	while (i <= str_len)
	{
		if (str[i] == (char) c)
			return ((char *) &str[i]);
		i++;
	}
	return (0);
}

void	ft_strlcat(char **dest, const char *src)
{
	char	*tmp;
	size_t	tmp_len;
	size_t	src_len;

	if (!src)
		return ;
	tmp_len = ft_strlen(*dest);
	src_len = ft_strlen(src);
	tmp = ft_strndup(*dest, tmp_len);
	free(*dest);
	*dest = (char *) malloc(sizeof(char) * (tmp_len + src_len + 1));
	if (!*dest)
		return ;
	ft_strncpy(*dest, tmp, tmp_len);
	ft_strncpy(*dest + tmp_len, src, src_len);
	free(tmp);
	return ;
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*ret;

	ret = (char *) malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (0);
	ft_strncpy(ret, src, n);
	return (ret);
}

void 	ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ;
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}