/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:55:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 14:36:42 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	init_map(t_map *map, int argc, char **argv)
{
	validate_file_name(argv[1]);
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		exit_with_error("Error: fail to malloc to map.\n");
	read_map_file(map, argv[1]);
	validate_map(map);
	return (TRUE);
}
