/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:08:30 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/01 16:57:13 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_coord		window_sz;
	t_map		*map;
	t_player	*player;
}	t_game;

t_bool	init_game(t_game *game, int argc, char **argv);

int		update_game(t_game *game);
int		reset_game(t_game *game);
int		end_game(t_game *game);

#endif