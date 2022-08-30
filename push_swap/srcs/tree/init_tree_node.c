/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:02:06 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/30 18:12:33 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/rb_tree.h"

t_tree_node	*init_tree_node(int val);

t_tree_node	*init_tree_node(int val)
{
	t_tree_node	*ret;

	ret = (t_tree_node *) malloc(sizeof(t_tree_node));
	if (!ret)
		ft_exit_with_error(0);
	ret->val = val;
	ret->color = RED;
	ret->left = 0;
	ret->right = 0;
	return (ret);
}