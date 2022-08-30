/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:03:21 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/30 18:04:17 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/rb_tree.h"

t_rb_tree	*init_tree(void);

t_rb_tree	*init_tree(void)
{
	t_rb_tree	*ret;

	ret = (t_rb_tree *) malloc(sizeof(t_rb_tree));
	if (!ret)
		return (0);
	ft_memset(ret, 0, sizeof(t_rb_tree));
	return (ret);
}