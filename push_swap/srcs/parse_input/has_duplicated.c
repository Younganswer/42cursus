/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:48:59 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 15:03:46 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parse_input.h"

t_bool		has_duplicated(t_stack *a);
static int	*stack_to_arr(t_stack *a);
static void	sort_arr(int *arr, int start, int end);
static void	ft_swap(int *a, int *b);

t_bool	has_duplicated(t_stack *a)
{
	int	*arr;
	int	i;

	arr = stack_to_arr(a);
	i = 0;
	while (i < a->sz_ - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			free(arr);
			return (TRUE);
		}
		i++;
	}
	free(arr);
	return (FALSE);
}

static int	*stack_to_arr(t_stack *a)
{
	t_node	*tmp;
	int		*ret;
	int		i;

	ret = (int *) malloc(sizeof(int) * (a->sz_));
	if (!ret)
		ft_exit_with_error(0, EXIT_FAILURE);
	i = 0;
	tmp = a->head;
	while (tmp)
	{
		ret[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	return (ret);
}

void	sort_arr(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (end <= start)
		return ;
	pivot = start;
	i = pivot + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (start < j && arr[pivot] <= arr[j])
			j--;
		if (j < i)
			ft_swap(&arr[pivot], &arr[j]);
		else
			ft_swap(&arr[i], &arr[j]);
	}
	sort_arr(arr, start, j - 1);
	sort_arr(arr, j + 1, end);
	return ;
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}
