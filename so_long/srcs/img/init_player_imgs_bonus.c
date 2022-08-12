/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_imgs_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 01:01:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/12 23:25:07 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool	init_player_imgs(t_game *game);

t_bool	init_player_imgs(t_game *game)
{
	init_player_down_imgs(game);
	init_player_left_imgs(game);
	init_player_right_imgs(game);
	init_player_up_imgs(game);
	return (TRUE);
}
