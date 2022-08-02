/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:54:35 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/02 12:15:18 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			read_map_file(char **char_map, char *file);
static t_bool	malloc_file(char **char_map, char *file);
static int		cnt_file_line(char *file);

t_bool	read_map_file(char **char_map, char *file)
{
	int	fd;
	int	i;

	malloc_file(char_map, file);
	fd = open(file, O_RDONLY);
	if (read(fd, 0, 0) == -1)
		exit_with_error("Error: fail to open file.\n");
	i = 0;
	while (TRUE)
	{
		char_map[i] = get_next_line(fd);
		if (!char_map[i])
			break;
		i++;
	}
	close(fd);
	return (TRUE);
}

static t_bool	malloc_file(char **char_map, char *file)
{
	int	lines;

	lines = cnt_file_line(file);
	char_map = malloc(sizeof(char *) * (lines + 1));
	if (!char_map)
		exit_with_error("Error: fail to malloc at char_map.\n");
	return (TRUE);
}

static int		cnt_file_line(char *file)
{
	int		lines;
	int		fd;
	int		read_bytes;
	char	c;

	fd = open(file, O_RDONLY);
	if (read(fd, 0, 0) == -1)
		exit_with_error("Error: fail to open file.\n");
	lines = 1;
	while (TRUE)
	{
		read_bytes = read(fd, &c, 1);
		if (!read_bytes)
			break ;
		if (read_bytes < 0)
			exit_with_error("Error: fail to read file.\n");
		if (c == '\n')
			lines++;
	}
	close(fd);
	return (lines);
}