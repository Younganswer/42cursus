/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:55:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/02 00:38:52 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	init_map(t_map *map, int argc, char **argv);
t_bool	file_is_not_valid(char *file);
t_bool	parse_map(t_tile **tile_map, char **char_map);
t_bool	init_img(t_tile_img *img);

t_bool	init_map(t_map *map, int argc, char **argv)
{
	if (file_is_not_valid(argv[1]))
		exit_with_error("Error: file is not valid.\n");
	if (!read_map_file(map->char_map, argv[1]))
		exit_with_error("Error: read_map() is not working well.\n");
	if (map_is_not_valid(map->char_map));
		exit_with_error("Error: map is not valid.\n");
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		exit_with_error("Error: fail to malloc in generating map.\n");
	if (!parse_map(map->tile_map, map->char_map))
		exit_with_error("Error: parse_map() is not working well.\n");
	if (!init_img(map->img))
		exit_with_error("Error: init_img() is not working well.\n");
	return (TRUE);
}

t_bool	file_is_not_valid(char *file)
{
	int file_len;

	file_len = ft_strlen(file);
	if (file_len < 5)
		return (TRUE);
	if (ft_strncmp(file + (file_len - 4), ".ber", 4))
		return (TRUE);
	return (FALSE);
}

t_bool	parse_map(t_tile **tile_map, char **char_map)
{
	return (TRUE);
}

t_bool	init_img(t_tile_img *img)
{
	return (TRUE);
}
