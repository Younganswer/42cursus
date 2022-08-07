/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:52:16 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/08 00:48:09 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "../mlx/mlx.h"

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/ft_printf/libft/includes/libft.h"
# include "../libs/get_next_line/includes/get_next_line.h"

# include "tools.h"

typedef struct s_map
{
	t_coord		size;
	char		**saved;
	char		**board;
}	t_map;

typedef struct s_player
{
	t_coord	position;
	int		moves;
	int		collects;
}	t_player;

typedef struct s_objs_img
{
	void	*empty_img;
	void	*wall_img;
	void	*collect_imgs[8];
	void	*player_imgs[32];
	void	*exit_imgs[33];
}	t_objs_img;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_coord		window_sz;
	t_objs_img	*img;
	t_coord		img_sz;
	t_map		*map;
	t_player	*player;
	int			collects;
}	t_game;

# include "map.h"
# include "player.h"
# include "img.h"
# include "game.h"

#endif