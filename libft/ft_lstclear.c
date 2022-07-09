/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:17:17 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/10 00:21:20 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*to_del;

	tmp = *lst;
	while (tmp)
	{
		to_del = tmp;
		ft_lstdelone(to_del, del);
		tmp = tmp->next;
	}
	free(lst);
	lst = 0;
	return ;
}
