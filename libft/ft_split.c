/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:16:25 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/09 01:53:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_split(char const *s, char c);
static size_t	cnt_words(char const *s, char c);
static size_t	cnt_word_len(char const *s, char c);
static char		*ft_strndup(const char *str, size_t n);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words_len;
	size_t	words_idx;
	size_t	word_len;
	size_t	s_idx;

	words_len = cnt_words(s, c);
	res = (char **) malloc(sizeof(char *) * (words_len + 1));
	if (!res || !s)
		return (0);
	words_idx = 0;
	s_idx = 0;
	while (s[s_idx] && words_idx < words_len)
	{
		while (s[s_idx] && s[s_idx] == c)
			s_idx++;
		if (s[s_idx])
		{
			word_len = cnt_word_len(&s[s_idx], c);
			res[words_idx++] = ft_strndup(&s[s_idx], word_len);
			s_idx += word_len;
		}
	}
	res[words_idx] = 0;
	return (res);
}

static size_t	cnt_words(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cnt);
}

static size_t	cnt_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_strndup(const char *str, size_t n)
{
	char	*res;

	res = (char *) malloc(sizeof(char) * (n + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, str, n + 1);
	return (res);
}
