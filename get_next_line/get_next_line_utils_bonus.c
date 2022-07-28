/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/28 15:33:00 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_init_list(int fd);
t_node	*ft_init_node(void);
int		ft_insert_node_to_cur_list(int fd, t_node *to_insert, t_list *cur_list);
int		ft_keep_reading(t_node *last_node);
char	*ft_strndup(const char *str, size_t n);

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

int	ft_insert_node_to_cur_list(int fd, t_node *to_insert, t_list *cur_list)
{
	if (!to_insert || !cur_list)
		return (0);
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

int	ft_keep_reading(t_node *last_node)
{
	size_t	i;

	if (!last_node || !last_node->buff)
		return (1);
	if (!last_node->buff[0])
		return (0);
	i = 0;
	while (last_node->buff[i])
	{
		if (last_node->buff[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
