/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/29 00:29:58 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_get_fd_list(int fd, t_list *fd_list);
t_node	*ft_init_node(void);
int		ft_keep_reading(t_list *cur_list);
size_t	ft_strlcat(char **dest, t_node *cur_node);
size_t	ft_strncpy(char *dest, const char *src, size_t n);

t_list	*ft_get_fd_list(int fd, t_list *fd_list)
{
	t_list	*ret;

	ret = fd_list;
	while (ret && ret->fd != fd && ret->next)
		ret = ret->next;
	if (ret && ret->fd == fd)
		return (ret);
	if (!ret)
		ret = (t_list *) malloc(sizeof(t_list));
	else if (ret && !ret->next)
	{
		ret->next = (t_list *) malloc(sizeof(t_list));
		ret = ret->next;
	}
	if (!ret)
		return (0);
	ret->fd = fd;
	ret->head = 0;
	ret->tail = 0;
	ret->next = 0;
	return (ret);
}

t_node	*ft_init_node(void)
{
	t_node	*ret;

	ret = (t_node *) malloc(sizeof(t_node));
	if (!ret)
		return (0);
	ret->buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ret->buff)
	{
		free(ret);
		return (0);
	}
	ret->idx = 0;
	ret->next = 0;
	return (ret);
}

int	ft_keep_reading(t_list *cur_list)
{
	t_node	*tmp;
	size_t	i;

	tmp = cur_list->tail;
	if (!tmp)
		return (1);
	if (!tmp->buff)
		return (1);
	if (!tmp->buff[0])
		return (0);
	i = tmp->idx;
	while (tmp->buff[i])
	{
		if (tmp->buff[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlcat(char **dest, t_node *cur)
{
	char	*save;
	size_t	d_len;
	size_t	s_len;
	size_t	start;

	d_len = 0;
	while (*dest && (*dest)[d_len])
		d_len++;
	save = (char *) malloc(sizeof(char) * (d_len + 1));
	if (!save)
		return (SIZE_MAX);
	ft_strncpy(save, *dest, d_len);
	start = cur->idx;
	s_len = cur->idx;
	while (cur->buff && cur->buff[s_len] && cur->buff[s_len] != '\n')
		s_len++;
	s_len += (cur->buff[s_len] == '\n');
	free(*dest);
	*dest = (char *) malloc(sizeof(char) * (d_len + s_len - start + 1));
	if (!(*dest))
		return (SIZE_MAX);
	ft_strncpy(*dest, save, d_len);
	free(save);
	cur->idx += ft_strncpy(*dest + d_len, &cur->buff[start], s_len - start);
	return (d_len + s_len - start);
}

size_t	ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (n);
}
