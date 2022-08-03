/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:54:35 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 21:32:31 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			read_map_file(t_game *game, char *file);
static t_bool	copy_to_board(t_game *game);
static t_bool	malloc_file(t_game *game, char *file);
static int		cnt_file_line(t_game *game, char *file);

t_bool	read_map_file(t_game *game, char *file)
{
	int	fd;
	int	i;

	malloc_file(game->map->saved, file);
	fd = open(file, O_RDONLY);
	if (read(fd, 0, 0) == -1)
	{
		free_all(game);
		exit_with_error("Error: Fail to open file.\n");
	}
	i = -1;
	game->map->size.x = sizeof(game->map->saved) / sizeof(char *);
	while (++i < game->map->size.x)
	{
		game->map->saved[i] = get_next_line(fd);
		game->map->size.y = ft_strlen(game->map->saved[i]);
		if (i && game->map->size.y != ft_strlen(game->map->saved[i - 1]))
		{
			free_all(game);
			exit_with_error("Error: Map must be rectangular.\n");
		}
	}
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
		exit_with_error("Error: Fail to malloc at board.\n");
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
			exit_with_error("Error: Fail to malloc at board.\n");
		}
		while (++j < game->map->size.y)
			game->map->board[i][j] = game->map->saved[i][j];
	}
	return (TRUE);
}

static t_bool	malloc_file(t_game *game, char *file)
{
	int	lines;

	lines = cnt_file_line(game, file);
	game->map->saved = malloc(sizeof(char *) * lines);
	if (!game->map->saved)
	{
		free_all(game);
		exit_with_error("Error: Fail to malloc at saved.\n");
	}
	return (TRUE);
}

static int	cnt_file_line(t_game *game, char *file)
{
	int		lines;
	int		fd;
	int		read_bytes;
	char	c;

	fd = open(file, O_RDONLY);
	if (read(fd, 0, 0) == -1)
	{
		free_all(game);
		exit_with_error("Error: Fail to open file.\n");
	}
	read_bytes = 1;
	lines = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, &c, 1);
		if (read_bytes < 0)
		{
			free_all(game);
			exit_with_error("Error: Fail to read file.\n");
		}
		lines += (c == '\n');
	}
	close(fd);
	return (lines);
}
