/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/28 00:27:18 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_init_list(int fd);
t_node	*ft_init_node(void);
int		ft_insert_node_to_fd_list(int fd, t_node *to_insert, t_list *fd_list);
char	*ft_strndup(const char *str, size_t n);
char	*ft_strchr(const char *str, int c);

t_list	*ft_init_list(int fd)
{
	t_list	*ret;

	ret = (t_list *) malloc(sizeof(t_list));
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
	ret->cur_idx = 0;
	ret->next = 0;
	return (ret);
}

int	ft_insert_node_to_fd_list(int fd, t_node *to_insert, t_list *fd_list)
{
	t_list	*list_tmp;

	list_tmp = fd_list;
	while (list_tmp)
	{
		if (list_tmp->fd == fd)
			break ;
		list_tmp = list_tmp->next;
	}
	if (!list_tmp)
		return (0);
	if (!list_tmp->head && !list_tmp->tail)
	{
		list_tmp->head = to_insert;
		list_tmp->tail = to_insert;
	}
	else
	{
		list_tmp->tail->next = to_insert;
		list_tmp->tail = list_tmp->tail->next;
	}
	return (1);
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
