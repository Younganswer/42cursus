/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:11:35 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/30 18:12:45 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/rb_tree.h"

t_bool		insert_node(int val);

t_bool		insert_node(int val)
{
	t_tree_node	*to_insert;

	to_insert = init_tree_node(val);
	
	return (TRUE);
}