/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:55:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/07 00:12:35 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	init_map(t_game *game, char *file)
{
	validate_file_name(game, file);
	game->map = (t_map *) malloc(sizeof(t_map));
	if (!game->map)
	{
		free_all(game);
		exit_with_error("Error: Fail to malloc to map.\n");
	}
	read_map_file(game, file);
	if (game->map->size.x < 4 || game->map->size.y < 4)
	{
		free_all(game);
		exit_with_error("Error: Map must be larger than 4x4.\n");
	}
	// validate_map(game);
	return (TRUE);
}
