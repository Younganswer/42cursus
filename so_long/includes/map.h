/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:17:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/06 22:11:18 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

typedef struct s_chk_map
{
	t_bool	player;
	int		exit;
	int		collects;
}	t_chk_map;

// init_map.c
t_bool	init_map(t_game *game, char *file);

// validate_file_name.c
t_bool	validate_file_name(t_game *game, char *file);

// read_map.c
t_bool	read_map_file(t_game *game, char *file);

// validate_map.c
t_bool	validate_map(t_game *game);

#endif