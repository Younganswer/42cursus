/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:46:41 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/28 22:30:14 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	char			*buff;
	size_t			idx;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	int				fd;
	t_node			*head;
	t_node			*tail;
	struct s_list	*next;
}	t_list;

// get_next_line_bonus.c
char	*get_next_line(int fd);
int		ft_read_fd(int fd, t_list *fd_list);
char	*ft_get_line_from_fd_list(int fd, t_list **fd_list);
int		ft_insert_node_to_cur_list(t_node *to_insert, t_list *cur_list);
int		ft_remove_line_from_fd_list(t_list *cur_list, t_list **fd_list);

// get_next_line_utils_bonus.c
t_list	*ft_get_fd_list(int fd, t_list *fd_list);
t_node	*ft_init_node(void);
int		ft_keep_reading(t_list *cur_list);
size_t	ft_strlcat(char **dest, t_node *cur_node);
size_t	ft_strdup(char **dest, const char *src);

#endif