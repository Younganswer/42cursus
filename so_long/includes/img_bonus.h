/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:45:11 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/12 23:29:07 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include "so_long_bonus.h"

// init_imgs_bonus.c
t_bool	init_imgs(t_game *game);

// init_collect_imgs_bonus.c
t_bool	init_collect_imgs(t_game *game);

// init_exit_imgs_bonus.c
t_bool	init_exit_imgs(t_game *game);

// init_ghost_imgs_bonus.c
t_bool	init_ghost_imgs(t_game *game);

// init_player_imgs_bonus.c
t_bool	init_player_imgs(t_game *game);

// init_player_down_imgs_bonus.c
t_bool	init_player_down_imgs(t_game *game);

// nit_player_left_imgs_bonus.c
t_bool	init_player_left_imgs(t_game *game);

// init_player_right_imgs_bonus.c
t_bool	init_player_right_imgs(t_game *game);

// init_player_up_imgs_bonus.c
t_bool	init_player_up_imgs(t_game *game);

#endif