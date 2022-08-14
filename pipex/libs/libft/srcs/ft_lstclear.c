/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:17:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/06 21:45:19 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list_libft **lst, void (*del)(void *))
{
	t_list_libft	*tmp;
	t_list_libft	*to_del;

	tmp = *lst;
	while (tmp)
	{
		to_del = tmp;
		tmp = tmp->next;
		ft_lstdelone(to_del, del);
	}
	*lst = 0;
	return ;
}
