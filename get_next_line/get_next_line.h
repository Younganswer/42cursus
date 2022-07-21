/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:53:47 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/22 00:50:43 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
void	ft_read_passed(int fd, char **passed);
char	*ft_get_line(const char *passed);
void	ft_new_passed(char **passed);
char	*ft_strchr(const char *str, int c);
char	*ft_strlcat(char **dest, const char *src);
char	*ft_strndup(const char *src, size_t n);
void	ft_strncpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *str);

#endif