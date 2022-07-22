/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:34:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/22 15:26:26 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
void	ft_read_file(int fd, char **saved);
char	*ft_get_line(const char *saved);
void	ft_remove_line_from_saved(char **saved);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ft_read_file(fd, &saved);
	if (!saved)
		return (0);
	line = ft_get_line(saved);
	ft_remove_line_from_saved(&saved);
	return (line);
}

void	ft_read_file(int fd, char **saved)
{
	char	*buff;
	int		read_bytes;

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		*saved = 0;
		return ;
	}
	read_bytes = 1;
	while (!ft_strchr(*saved, '\n') && read_bytes)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return ;
		}
		buff[read_bytes] = '\0';
		ft_strlcat(saved, buff);
		if (!*saved)
			return ;
	}
	free(buff);
	return ;
}

char	*ft_get_line(const char *saved)
{
	size_t	len;

	len = 0;
	if (!saved[len])
		return (0);
	while (saved[len] && saved[len] != '\n')
		len++;
	if (saved[len] == '\n')
		return (ft_strndup(saved, len + 1));
	return (ft_strndup(saved, len));
}

void	ft_remove_line_from_saved(char **saved)
{
	char	*tmp;
	size_t	saved_len;
	size_t	i;

	saved_len = ft_strlen(*saved);
	tmp = ft_strndup(*saved, saved_len);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	free(*saved);
	if (!tmp[i])
	{
		*saved = 0;
		return ;
	}
	*saved = (char *) malloc(sizeof(char) * (saved_len - i + 1));
	if (!*saved)
		return ;
	ft_strncpy(*saved, tmp + i, saved_len - i);
	free(tmp);
	return ;
}
