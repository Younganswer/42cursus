/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:57:14 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/05 21:25:37 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_H
# define MERGE_H

# include "../libs/ft_printf/libft/incs/libft.h"
# include "structs.h"
# include "stack.h"

// merge.c
t_bool	merge(t_var *var);

// make_normal.c
t_bool	make_normal(t_var *var);

// make_reversed.c
t_bool	make_reversed(t_var *var);

#endif