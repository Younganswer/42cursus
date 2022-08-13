/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:17:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/13 14:18:27 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include "so_long_bonus.h"

typedef struct s_chk_map
{
	t_bool	player;
	int		exit;
	int		collects;
}	t_chk_map;

// init_map_bonus.c
t_bool	init_map(t_game *game, char *file);

// validate_file_name_bonus.c
t_bool	validate_file_name(t_game *game, char *file);

// read_map_bonus.c
t_bool	read_map_file(t_game *game, char *file);

// validate_map_bonus.c
t_bool	validate_map(t_game *game);

#endif