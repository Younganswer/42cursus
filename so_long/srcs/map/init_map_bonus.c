/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:55:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/18 16:24:07 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool			init_map(t_game *game, char *file);
static t_bool	copy_to_board(t_game *game);

t_bool	init_map(t_game *game, char *file)
{
	validate_file_name(game, file);
	game->map = (t_map *) malloc(sizeof(t_map));
	if (!game->map)
	{
		free_all(game);
		exit_with_error("Error: Fail to malloc to map.\n");
	}
	ft_memset(game->map, 0, sizeof(game->map));
	read_map_file(game, file);
	copy_to_board(game);
	validate_map(game);
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
