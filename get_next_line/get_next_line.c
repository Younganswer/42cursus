/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:54:57 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/27 18:10:08 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
int		ft_read_fd(int fd, t_list *fd_list);
char	*ft_get_line_from_fd_list(int fd, t_list *fd_list);
void	ft_remove_line_from_fd_list(int fd, t_list *fd_list);
char	*ft_destroy_fd_list(t_list *fd_list);

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*fd_list;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!fd_list)
	{
		fd_list = (t_list *) malloc(sizeof(t_list));
		if (!fd_list)
			return (0);
		fd_list->head = 0;
		fd_list->next = 0;
	}
	if (!ft_read_fd(fd, fd_list))
		return (ft_destroy_fd_list(fd_list));
	line = ft_get_line_from_fd_list(fd, fd_list);
	ft_remove_line_from_fd_list(fd, fd_list);
	if (!fd_list->head && !fd_list->next)
	{
		free(fd_list);
		fd_list = 0;
	}
	return (line);
}

int	ft_read_fd(int fd, t_list *fd_list)
{
	t_node	*tmp;
	int		read_bytes;

	tmp = ft_get_fd_last_node_from_fd_list(fd, fd_list);
	read_bytes = 1;
	while (read_bytes && (!tmp || (tmp && !ft_strchr(tmp->buff, '\n')
				&& tmp->buff_sz == BUFFER_SIZE)))
	{
		if (tmp)
		{
			tmp->next = ft_init_node(fd);
			tmp = tmp->next;
		}
		else
			tmp = ft_insert_new_fd_to_fd_list(fd, fd_list);
		if (!tmp)
			return (0);
		read_bytes = read(fd, tmp->buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (0);
		tmp->buff[read_bytes] = '\0';
		tmp->buff_sz = read_bytes;
	}
	return (1);
}

char	*ft_get_line_from_fd_list(int fd, t_list *fd_list)
{
	char	*ret;
	t_node	*tmp;
	size_t	start;

	while (fd_list && fd_list->head->fd != fd)
		fd_list = fd_list->next;
	if (!fd_list)
		return (0);
	tmp = fd_list->head;
	start = tmp->cur_idx;
	while (tmp->buff[tmp->cur_idx] && tmp->buff[tmp->cur_idx] != '\n')
		tmp->cur_idx++;
	if (tmp->buff[tmp->cur_idx] == '\n')
		tmp->cur_idx++;
	ret = ft_strndup(&tmp->buff[start], tmp->cur_idx - start);
	if (!ret)
		return (0);
	return (ret);
}

void	ft_remove_line_from_fd_list(int fd, t_list *fd_list)
{
	t_list	*list_prev;
	t_list	*list_cur;
	t_node	*to_del;

	list_prev = fd_list;
	list_cur = fd_list;
	while (list_cur && list_cur->head->fd != fd)
	{
		list_prev = list_cur;
		list_cur = list_cur->next;
	}
	if (!list_cur || list_cur->head->buff[list_cur->head->cur_idx])
		return ;
	to_del = list_cur->head;
	list_cur->head = list_cur->head->next;
	free(to_del->buff);
	free(to_del);
	if (list_cur != fd_list && !list_cur->head)
	{
		list_prev->next = list_cur->next;
		free(list_cur);
	}
	return ;
}

char	*ft_destroy_fd_list(t_list *fd_list)
{
	t_list	*list_tmp;
	t_list	*list_to_del;
	t_node	*node_tmp;
	t_node	*node_to_del;

	if (!fd_list)
		return (0);
	list_tmp = fd_list;
	while (list_tmp)
	{
		list_to_del = list_tmp;
		list_tmp = list_tmp->next;
		node_tmp = list_to_del->head;
		while (node_tmp)
		{
			node_to_del = node_tmp;
			node_tmp = node_tmp->next;
			free(node_to_del->buff);
			free(node_to_del);
		}
		free(list_to_del);
	}
	return (0);
}
