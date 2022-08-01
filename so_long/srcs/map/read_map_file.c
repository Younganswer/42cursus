/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:54:35 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/02 00:10:30 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			read_map_file(char **char_map, char *file);
static t_bool	alloc_file(char **char_map, char *file);
static int		cnt_file_line(char *file);

t_bool	read_map_file(char **char_map, char *file)
{
	int	fd;
	int	i;

	alloc_file(char_map, file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
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

static t_bool	alloc_file(char **char_map, char *file)
{
	int	lines;

	lines = cnt_file_line(file);
	if (lines == -1)
		exit_with_error("Error: fail to open or read file.\n");
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
	if (fd < 0)
		return (-1);
	lines = 1;
	while (TRUE)
	{
		read_bytes = read(fd, &c, 1);
		if (!read_bytes)
			break ;
		if (read_bytes < 0)
			return (-1);
		if (c == '\n')
			lines++;
	}
	close(fd);
	return (lines);
}