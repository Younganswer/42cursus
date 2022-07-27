/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:46:41 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/27 17:41:17 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	int				fd;
	char			*buff;
	size_t			buff_sz;
	size_t			cur_idx;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node			*head;
	struct s_list	*next;
}	t_list;

// get_next_line_bonus.c
char	*get_next_line(int fd);
int		ft_read_fd(int fd, t_list *fd_list);
char	*ft_get_line_from_fd_list(int fd, t_list *fd_list);
void	ft_remove_line_from_fd_list(int fd, t_list *fd_list);
char	*ft_destroy_fd_list(t_list *fd_list);

// get_next_line_utils_bonus.c
t_node	*ft_get_fd_last_node_from_fd_list(int fd, t_list *fd_list);
t_node	*ft_insert_new_fd_to_fd_list(int fd, t_list *fd_list);
t_node	*ft_init_node(int fd);
char	*ft_strndup(const char *str, size_t n);
char	*ft_strchr(const char *str, int c);

#endif