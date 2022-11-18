/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:04:10 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/18 15:50:59 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/iter.hpp"

int	main(void) {
	{
		int	arr[5] = {0, 1, 2, 3, 4};
		ft::iter(arr, 5, ft::print);
	}
	{
		std::string	arr[5] = {"Hello", "World", "!", "I'm", "Younhwan"};
		ft::iter(arr, 5, ft::print);
	}
	return (0);
}