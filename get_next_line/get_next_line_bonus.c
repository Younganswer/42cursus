/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:54:57 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/26 16:18:03 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd);
int		ft_read_fd(int fd, t_list *fd_list);
char	*ft_get_line_from_fd_list(int fd, t_list *fd_list);
void	ft_remove_line_from_fd_list(int fd, t_list *fd_list);

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
		return (!ft_destroy_fd_list(fd_list));
	line = ft_get_line_from_fd_list(fd, fd_list);
	ft_remove_line_from_fd_list(fd, fd_list);
	if (!fd_list->head)
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

	tmp = ft_get_fd_node_from_fd_list(fd, fd_list);
	if (!tmp)
	{
		tmp = ft_insert_new_fd_to_fd_list(fd, fd_list);
		if (!tmp)
			return (0);
	}
	tmp->buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp->buff)
		return (0);
	read_bytes = 1;
	while (!ft_strchr(tmp->buff, '\n') && read_bytes)
	{
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
	size_t	len;
	size_t	i;

	tmp = ft_get_fd_node_from_fd_list(fd, fd_list);
	if (!tmp)
		return (0);
	len = 0;
	while (tmp->buff[len] && tmp->buff[len] != '\n')
		len++;
	if (tmp->buff[len] == '\n')
		len++;
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = tmp->buff[i];
		i++;
	}
	ret[i] = '\0';
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
	if (!list_cur)
		return ;
	to_del = list_cur->head;
	list_cur->head = list_cur->head->next;
	free(to_del->buff);
	free(to_del);
	if (!list_cur->head)
	{
		list_prev->next = list_cur->next;
		free(list_cur);
	}
	return ;
}
