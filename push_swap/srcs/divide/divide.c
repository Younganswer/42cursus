/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:58:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 19:52:47 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"
#include "../../incs/stack.h"

t_bool	divide(t_var *var)
{
	set_size_of_triangles(var);
	if (var->size_of_triangles_in_a->sz_)
		print_stack(var->size_of_triangles_in_a);
	else if (var->size_of_triangles_in_b->sz_)
		print_stack(var->size_of_triangles_in_b);
	return (TRUE);
}
