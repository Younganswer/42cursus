/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:02:56 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/06 21:45:19 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstnew(void *content)
{
	t_list_libft	*new;

	new = (t_list_libft *) malloc(sizeof(t_list_libft));
	if (!new)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}
