/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:04:10 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/18 15:40:15 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../incs/Array.hpp"

int	main(void) {
	{
		Array<int>	arr(5);
		for (int i=0; i<5; i++)
			arr[i] = i;
		for (int i=0; i<5; i++) {
			try {
				std::cout << arr[i] << '\n';
			} catch (std::exception &e) {
				std::cout << e.what() << '\n';
			}
		}
		try {
			std::cout << arr[-1] << '\n';
		} catch (std::exception &e) {
			std::cout << e.what() << '\n';
		}
	}
	{
		Array<std::string>	arr(5);
		std::string			str[5] = {"Hello", "World", "!", "I'm", "younhwan"};
		for (int i=0; i<5; i++)
			arr[i] = str[i];
		for (int i=0; i<=5; i++) {
			try {
				std::cout << arr[i] << '\n';
			} catch (std::exception &e) {
				std::cout << e.what() << '\n';
			}
		}
	}
	return (0);
}