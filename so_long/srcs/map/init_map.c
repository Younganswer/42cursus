/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:55:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 19:46:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	init_map(t_game *game, int argc, char **argv)
{
	validate_file_name(game, argv[1]);
	game->map = (t_map *) malloc(sizeof(t_map));
	if (!game->map)
		exit_with_error("Error: fail to malloc to map.\n");
	read_map_file(game, argv[1]);
	validate_map(game);
	return (TRUE);
}
