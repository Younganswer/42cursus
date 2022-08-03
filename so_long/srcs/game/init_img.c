/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:43:27 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 18:43:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	init_img(t_obj_img *img, void *mlx);

t_bool	init_img(t_obj_img *obj_img, void *mlx)
{
	obj_img->road_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/road.xpm", TILE_SIZE, TILE_SIZE);
	if (!obj_img->road_img)
		exit_with_error("Error: Fail to read road image.\n");
	obj_img->wall_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/trees.xpm", TILE_SIZE, TILE_SIZE);
	if (!obj_img->wall_img)
		exit_with_error("Error: Fail to read wall image.\n");
	obj_img->under_wall_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/grass.xpm", TILE_SIZE, TILE_SIZE);
	if (!obj_img->under_wall_img)
		exit_with_error("Error: Fail to read under wall image.\n");
	obj_img->collects_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/apple.xpm", TILE_SIZE, TILE_SIZE);
	if (!obj_img->collects_img)
		exit_with_error("Error: Fail to read collects image.\n");
	init_exit_img(obj_img, mlx);
	init_player_img(obj_img, mlx);
	return (TRUE);
}

static t_bool	init_exit_img(t_obj_img *obj_img, void *mlx)
{
	obj_img->exit_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/door_close.xpm", TILE_SIZE, TILE_SIZE);
	if (!obj_img->exit_img)
		exit_with_error("Error: Fail to read exit image.\n");
	return (TRUE);
}

static t_bool	init_player_img(t_obj_img *obj_img, void *mlx)
{
	obj_img->player_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/BryceSlime/idle/BryceIdle1.xpm",\
			TILE_SIZE, TILE_SIZE);
	if (!obj_img->player_img)
		exit_with_error("Error: Fail to read player image.\n");
	return (TRUE);
}
