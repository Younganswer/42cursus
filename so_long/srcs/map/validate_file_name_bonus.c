/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_name_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:28:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/12 23:25:50 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool	validate_file_name(t_game *game, char *file)
{
	int	file_len;

	file_len = ft_strlen(file);
	if (file_len < 5)
	{
		free_all(game);
		exit_with_error("Error: File name must be longer than 4 characters.\n");
	}
	if (ft_strncmp(file + (file_len - 4), ".ber", 4))
	{
		free_all(game);
		exit_with_error("Error: File name must end with [.ber].\n");
	}
	return (TRUE);
}
