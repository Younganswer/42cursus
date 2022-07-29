/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:54:57 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/29 11:21:22 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd);
int		ft_read_fd(int fd, t_list *fd_list);
char	*ft_get_line_from_fd_list(int fd, t_list **fd_list);
int		ft_insert_node_to_cur_list(t_node *to_insert, t_list *cur_list);
int		ft_remove_line_from_fd_list(t_list **cur_list, t_list **fd_list);

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*fd_list;
	t_list			*to_del;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!fd_list)
	{
		fd_list = ft_get_fd_list(fd, fd_list);
		if (!fd_list)
			return (0);
	}
	if (!ft_read_fd(fd, fd_list))
	{
		to_del = ft_get_fd_list(fd, fd_list);
		while (to_del)
			ft_remove_line_from_fd_list(&to_del, &fd_list);
		return (0);
	}
	line = ft_get_line_from_fd_list(fd, &fd_list);
	return (line);
}

int	ft_read_fd(int fd, t_list *fd_list)
{
	t_list	*list_tmp;
	t_node	*node_tmp;
	int		read_bytes;

	list_tmp = ft_get_fd_list(fd, fd_list);
	if (!list_tmp)
		return (0);
	read_bytes = 1;
	while (ft_keep_reading(list_tmp) && read_bytes)
	{
		node_tmp = ft_init_node();
		if (!node_tmp)
			return (0);
		ft_insert_node_to_cur_list(node_tmp, list_tmp);
		read_bytes = read(fd, node_tmp->buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (0);
		node_tmp->buff[read_bytes] = '\0';
	}
	return (1);
}

char	*ft_get_line_from_fd_list(int fd, t_list **fd_list)
{
	char	*ret;
	size_t	last_idx;
	t_list	*list_tmp;
	t_node	*node_tmp;

	ret = 0;
	list_tmp = ft_get_fd_list(fd, *fd_list);
	node_tmp = list_tmp->head;
	last_idx = 1;
	while (node_tmp && (!ret || (ret && ret[last_idx - 1] != '\n')))
	{
		if (node_tmp->buff[node_tmp->idx])
			last_idx = ft_strlcat(&ret, node_tmp);
		if (last_idx == SIZE_MAX)
			while (list_tmp)
				if (ft_remove_line_from_fd_list(&list_tmp, fd_list))
					return (0);
		if (!node_tmp->buff[node_tmp->idx])
		{
			node_tmp = node_tmp->next;
			ft_remove_line_from_fd_list(&list_tmp, fd_list);
		}
	}
	return (ret);
}

int	ft_insert_node_to_cur_list(t_node *to_insert, t_list *cur_list)
{
	if (!cur_list->head && !cur_list->tail)
	{
		cur_list->head = to_insert;
		cur_list->tail = to_insert;
	}
	else
	{
		cur_list->tail->next = to_insert;
		cur_list->tail = cur_list->tail->next;
	}
	return (1);
}

int	ft_remove_line_from_fd_list(t_list **cur_list, t_list **fd_list)
{
	t_node	*node_to_del;
	t_list	*list_prev;

	node_to_del = (*cur_list)->head;
	(*cur_list)->head = (*cur_list)->head->next;
	free(node_to_del->buff);
	free(node_to_del);
	if ((*cur_list)->head)
		return (0);
	if ((*cur_list) == (*fd_list))
	{
		*fd_list = (*fd_list)->next;
		free(*cur_list);
		(*cur_list) = 0;
		return (1);
	}
	list_prev = *fd_list;
	while (list_prev->next->fd != (*cur_list)->fd)
		list_prev = list_prev->next;
	list_prev->next = (*cur_list)->next;
	free((*cur_list));
	(*cur_list) = 0;
	return (1);
}
