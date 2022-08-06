/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:54:35 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/07 01:12:39 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			read_map_file(t_game *game, char *file);
static t_bool	copy_to_board(t_game *game);
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
	while (TRUE)
		;
	while (++i < game->map->size.x)
	{
		game->map->saved[i] = get_next_line(fd);
		if (!game->map->saved[i])
		{
			free_all(game);
			exit_with_error("Error\nFail to malloc at saved.\n");
		}
		if (i && (size_t)game->map->size.y != \
			ft_strlen(game->map->saved[i - 1]) - 1)
		{
			free_all(game);
			exit_with_error("Error\nMap must be rectangular.\n");
		}
		game->map->size.y = ft_strlen(game->map->saved[i]) - 1;
	}
	copy_to_board(game);
	close(fd);
	return (TRUE);
}

static t_bool	copy_to_board(t_game *game)
{
	int	i;
	int	j;

	game->map->board = (char **) malloc(sizeof(char *) * (game->map->size.x));
	if (!game->map->board)
	{
		free_all(game);
		exit_with_error("Error\nFail to malloc at board.\n");
	}
	i = -1;
	while (++i < game->map->size.x)
	{
		j = -1;
		game->map->board[i] = (char *) \
			malloc(sizeof(char) * (game->map->size.y));
		if (!game->map->board[i])
		{
			free_all(game);
			exit_with_error("Error\nFail to malloc at board.\n");
		}
		while (++j < game->map->size.y)
			game->map->board[i][j] = game->map->saved[i][j];
	}
	return (TRUE);
}

static t_bool	malloc_file(t_game *game, char *file)
{
	int	lines;

	lines = cnt_file_lines(game, file);
	game->map->size.x = lines;
	game->map->saved = (char **) malloc(sizeof(char *) * lines);
	if (!game->map->saved)
	{
		free_all(game);
		exit_with_error("Error\nFail to malloc at saved.\n");
	}
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
	lines = 0;
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
