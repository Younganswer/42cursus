/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/27 18:12:22 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_node	*ft_get_fd_last_node_from_fd_list(int fd, t_list *fd_list);
t_node	*ft_insert_new_fd_to_fd_list(int fd, t_list *fd_list);
t_node	*ft_init_node(int fd);
char	*ft_strndup(const char *str, size_t n);
char	*ft_strchr(const char *str, int c);

t_node	*ft_get_fd_last_node_from_fd_list(int fd, t_list *fd_list)
{
	t_list	*list_tmp;
	t_node	*node_tmp;

	list_tmp = fd_list;
	while (list_tmp && list_tmp->head)
	{
		if (list_tmp->head->fd == fd)
		{
			node_tmp = list_tmp->head;
			while (node_tmp->next)
				node_tmp = node_tmp->next;
			return (node_tmp);
		}
		list_tmp = list_tmp->next;
	}
	return (0);
}

t_node	*ft_insert_new_fd_to_fd_list(int fd, t_list *fd_list)
{
	t_list	*list_tmp;

	list_tmp = fd_list;
	while (list_tmp->next)
		list_tmp = list_tmp->next;
	if (list_tmp->head)
	{
		list_tmp->next = (t_list *) malloc(sizeof(t_list));
		if (!list_tmp->next)
			return (0);
		list_tmp = list_tmp->next;
	}
	list_tmp->head = ft_init_node(fd);
	if (!list_tmp->head)
	{
		free(list_tmp);
		return (0);
	}
	return (list_tmp->head);
}

t_node	*ft_init_node(int fd)
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
	ret->fd = fd;
	ret->buff_sz = BUFFER_SIZE;
	ret->cur_idx = 0;
	ret->next = 0;
	return (ret);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*ret;
	size_t	i;

	ret = (char *) malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < n)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == (char) c)
		return ((char *) &str[i]);
	return (0);
}
