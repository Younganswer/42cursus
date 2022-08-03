/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:17:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 21:25:56 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_chk_map
{
	t_bool	player;
	int		exit;
	int		collects;
}	t_chk_map;

typedef struct s_map
{
	t_coord		size;
	char		**saved;
	char		**board;
}	t_map;

// init_map.c
t_bool	init_map(t_game *game, int argc, char **argv);

// validate_file_name.c
t_bool	validate_file_name(t_game *game, char *file);

// read_map.c
t_bool	read_map_file(t_game *game, char *file);

// validate_map.c
t_bool	validate_map(t_game *game);

#endif