/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:58:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 17:54:22 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/divide.h"
#include "../../incs/stack.h"

t_bool	divide(t_var *var)
{
	set_size_of_triangles(var);
	print_stack(var->b);	
	return (TRUE);
}
