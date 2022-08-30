/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:54:53 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/30 18:11:44 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_H
# define RB_TREE_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"

typedef enum e_color
{
	BLACK = 0,
	RED = 1,
}	t_color;

typedef struct s_tree_node
{
	int					val;
	t_color				color;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}	t_tree_node;

typedef struct s_rb_tree
{
	t_tree_node	*root;
	size_t		sz_;	
}	t_rb_tree;

// init_tree_node.c
t_tree_node	*init_tree_node(int val);

// init_tree.c
t_rb_tree	*init_tree(void);

// insert_node.c
t_bool		insert_node(int val);

#endif