/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:54:35 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/23 18:33:06 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool			read_map_file(t_game *game, char *file);
static t_bool	set_map_width(t_game *game, int i);
static t_bool	malloc_file(t_game *game, char *file);
static int		cnt_file_lines(t_game *game, char *file);
static t_bool	chk_fd_is_valid(t_game *game, int fd);

t_bool	read_map_file(t_game *game, char *file)
{
	int	fd;
	int	i;

	malloc_file(game, file);
	fd = open(file, O_RDONLY);
	chk_fd_is_valid(game, fd);
	i = -1;
	while (++i < game->map->size.x)
	{
		game->map->saved[i] = get_next_line(fd);
		if (!game->map->saved[i])
		{
			free_all(game);
			if (!i)
				exit_with_error("Error\nMap file is empty.\n");
			exit_with_error("Error\nFail to malloc at saved.\n");
		}
		set_map_width(game, i);
	}
	close(fd);
	return (TRUE);
}

static t_bool	set_map_width(t_game *game, int i)
{
	if (!i)
		game->map->size.y = ft_strlen(game->map->saved[i]) - 1;
	else if (i == game->map->size.x - 1)
	{
		if ((size_t)game->map->size.y == ft_strlen(game->map->saved[i]) - 1 && \
			game->map->saved[i][game->map->size.y] == '\n')
			return (TRUE);
		else if ((size_t)game->map->size.y == ft_strlen(game->map->saved[i]) && \
			game->map->saved[i][game->map->size.y - 1] != '\n')
			return (TRUE);
		else
		{
			free_all(game);
			exit_with_error("Error\nMap must be rectangular.\n");
		}
	}
	else if ((0 < i && i < game->map->size.x - 1) && \
		(size_t)game->map->size.y != ft_strlen(game->map->saved[i]) - 1)
	{
		free_all(game);
		exit_with_error("Error\nMap must be rectangular.\n");
	}
	return (TRUE);
}

static t_bool	malloc_file(t_game *game, char *file)
{
	int	lines;
	int	i;

	lines = cnt_file_lines(game, file);
	game->map->size.x = lines;
	game->map->saved = (char **) malloc(sizeof(char *) * lines);
	if (!game->map->saved)
	{
		free_all(game);
		exit_with_error("Error\nFail to malloc at saved.\n");
	}
	i = 0;
	while (i < lines)
		game->map->saved[i++] = 0;	
	return (TRUE);
}

static int	cnt_file_lines(t_game *game, char *file)
{
	int		lines;
	int		fd;
	int		read_bytes;
	char	c;

	fd = open(file, O_RDONLY);
	chk_fd_is_valid(game, fd);
	lines = 1;
	while (TRUE)
	{
		read_bytes = read(fd, &c, 1);
		if (!read_bytes)
			break ;
		if (read_bytes == -1)
		{
			free_all(game);
			exit_with_error("Error\nFail to read file.\n");
		}
		if (c == '\n')
			lines++;
	}
	if (c == '\n')
		lines--;
	close(fd);
	return (lines);
}

static t_bool	chk_fd_is_valid(t_game *game, int fd)
{
	if (read(fd, 0, 0) == -1)
	{
		free_all(game);
		exit_with_error("Error\nFail to open file.\n");
	}
	return (TRUE);
}
