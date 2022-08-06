/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:55:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/06 22:12:25 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	init_map(t_game *game, char *file)
{
	validate_file_name(game, file);
	game->map = (t_map *) malloc(sizeof(t_map));
	if (!game->map)
		exit_with_error("Error: fail to malloc to map.\n");
	read_map_file(game, file);
	validate_map(game);
	return (TRUE);
}
