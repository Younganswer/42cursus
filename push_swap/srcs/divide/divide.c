/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:58:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 22:05:59 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"
#include "../../incs/stack.h"

// static t_bool	divide_in_triangles(t_var *var);

t_bool	divide(t_var *var)
{
	set_triangles(var);
	print_stack(var->size_of_triangles_in_b);
	// divide_in_triangles(var);
	return (TRUE);
}

// static t_bool	divide_in_triangles(t_var *var)
// {
// 	var->a_to_b ^= 1;
// 	if (var->a_to_b)
// 		divide_in_b(var);
// 	else
// 	{
// 		while (var->a->sz_)
// 			pb(var->a, var->b);
// 		divide_in_a(var);
// 	}
// 	return (TRUE);
// }
