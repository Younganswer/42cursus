/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:43:27 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/06 22:10:07 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			init_img(t_game *game);
static t_bool	init_map_imgs(t_game *game);
static t_bool	init_exit_imgs(t_game *game);
static t_bool	init_player_imgs(t_game *game);

t_bool	init_img(t_game *game)
{
	init_map_imgs(game);
	init_exit_imgs(game);
	init_player_imgs(game);
	return (TRUE);
}

static t_bool	init_map_imgs(t_game *game)
{
	game->img->road_img = mlx_xpm_file_to_image(\
		game->mlx, "../../assets/road.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->wall_img = mlx_xpm_file_to_image(\
		game->mlx, "../../assets/trees.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->under_wall_img = mlx_xpm_file_to_image(\
		game->mlx, "../../assets/grass.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collects_img = mlx_xpm_file_to_image(\
		game->mlx, "../../assets/apple.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->road_img || !game->img->wall_img || \
		!game->img->under_wall_img || !game->img->collects_img)
	{
		free_all(game);
		exit_with_error("Error: Fail to read map images.\n");
	}
	return (TRUE);
}

static t_bool	init_exit_imgs(t_game *game)
{
	game->img->exit_img = mlx_xpm_file_to_image(\
		game->mlx, "../../assets/door_close.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->exit_img)
	{
		free_all(game);
		exit_with_error("Error: Fail to read exit images.\n");
	}
	return (TRUE);
}

static t_bool	init_player_imgs(t_game *game)
{
	game->img->player_img = mlx_xpm_file_to_image(\
		game->mlx, "../../assets/BryceSlime/idle/BryceIdle1.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->player_img)
	{
		free_all(game);
		exit_with_error("Error: Fail to read player images.\n");
	}
	return (TRUE);
}
