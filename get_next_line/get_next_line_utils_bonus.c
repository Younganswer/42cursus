/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/26 15:40:59 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_node	*ft_get_fd_node_from_fd_list(int fd, t_list *fd_list);
int		ft_destroy_fd_list(t_list *fd_list);
t_node	*ft_insert_new_fd_to_fd_list(int fd, t_list *fd_list);

t_node	*ft_get_fd_node_from_fd_list(int fd, t_list *fd_list)
{
	t_list	*list_tmp;
	t_node	*node_tmp;

	list_tmp = fd_list;
	while (list_tmp)
	{
		if (list_tmp->head->fd == fd)
		{
			node_tmp = list_tmp->head;
			while (node_tmp->next)
				node_tmp = node_tmp->next;
			node_tmp->next = (t_node *) malloc(sizeof(t_node));
			if (!node_tmp->next)
				return (0);
			node_tmp = node_tmp->next;
			node_tmp->fd = fd;
			node_tmp->next = 0;
			return (node_tmp);
		}
		list_tmp = list_tmp->next;
	}
	return (0);
}

int	ft_destroy_fd_list(t_list *fd_list)
{
	t_list	*list_tmp;
	t_list	*list_to_del;
	t_node	*node_tmp;
	t_node	*node_to_del;

	if (!fd_list)
		return (1);
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
	return (1);
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
	list_tmp->head = (t_node *) malloc(sizeof(t_node));
	if (!list_tmp->head)
		return (0);
	list_tmp->head->fd = fd;
	list_tmp->head->next = 0;
	list_tmp->next = 0;
	return (list_tmp->head);
}
