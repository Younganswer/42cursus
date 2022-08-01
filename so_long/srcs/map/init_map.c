/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:55:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/01 17:06:25 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	init_map(t_map *map, int argc, char **argv);
t_bool	map_is_not_valid(int argc, char **argv);
t_bool	read_map(char **char_map, char **argv);
t_bool	parse_map(t_tile **tile_map, char **char_map);
t_bool	init_img(t_tile_img *img);

t_bool	init_map(t_map *map, int argc, char **argv)
{
	if (map_is_not_valid(argc, argv[1]))
		return (FALSE);
	if (!read_map(map->char_map, argv[1]))
		return (FALSE);
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (FALSE);
	if (!parse_map(map->tile_map, map->char_map))
	{
		free(map);
		map = 0;
		return (FALSE);
	}
	if (!init_img(map->img))
	{
		free(map);
		map = 0;
		return (FALSE);
	}
	return (TRUE);
}

t_bool	map_is_not_valid(int argc, char **argv)
{
	return (FALSE);
}

t_bool	read_map(char **char_map, char **argv)
{
	return (TRUE);
}

t_bool	parse_map(t_tile **tile_map, char **char_map)
{
	return (TRUE);
}

t_bool	init_img(t_tile_img *img)
{
	return (TRUE);
}
