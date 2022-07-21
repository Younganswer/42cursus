/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:34:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/22 00:58:56 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
void	ft_read_passed(int fd, char **passed);
char	*ft_get_line(const char *passed);
void	ft_new_passed(char **passed);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*passed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ft_read_passed(fd, &passed);
	if (!passed)
		return (0);
	line = ft_get_line(passed);
	ft_new_passed(&passed);
	return (line);
}

void	ft_read_passed(int fd, char **passed)
{
	char	*buff;
	int		readBytes;

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return ;
	readBytes = 1;
	while (!ft_strchr(*passed, '\n') && readBytes)
	{
		readBytes = read(fd, buff, BUFFER_SIZE);
		if (readBytes == -1)
		{
			free(buff);
			return ;
		}
		buff[readBytes] = '\0';
		ft_strlcat(passed, buff);
	}
	free(buff);
	return ;
}

char	*ft_get_line(const char *passed)
{
	size_t	len;

	len = 0;
	if (!passed[len])
		return (0);
	while (passed[len] && passed[len] != '\n')
		len++;
	if (passed[len] == '\n')
		return (ft_strndup(passed, len + 1));
	return (ft_strndup(passed, len));
}

void	ft_new_passed(char **passed)
{
	char	*tmp;
	size_t	passed_len;
	size_t	i;

	passed_len = ft_strlen(*passed);
	tmp = ft_strndup(*passed, passed_len);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	free(*passed);
	if (!tmp[i])
	{
		*passed = 0;
		return ;
	}
	*passed = (char *) malloc(sizeof(char) * (passed_len - i++ + 1));
	if (!*passed)
		return ;
	ft_strncpy(*passed, tmp + i, passed_len - i);
	free(tmp);
	return ;
}