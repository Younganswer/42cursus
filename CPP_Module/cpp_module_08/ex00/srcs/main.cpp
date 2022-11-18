/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:34:49 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/18 16:46:43 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "../incs/easyfind.hpp"

int	main(void) {
	{
		std::vector<int>	v;
		for (size_t i=0; i<10; i++) {
			v.push_back(i);
		}
		
		try {
			std::vector<int>::iterator it = easyfind(v, 5);
			std::cout << "Found: " << *it << '\n';
		} catch (std::exception &e) {
			std::cout << "Not Found" << '\n';
		}
		try {
			std::vector<int>::iterator it = easyfind(v, 10);
			std::cout << "Found: " << *it << '\n';
		} catch (std::exception &e) {
			std::cout << "Not Found" << '\n';
		}
	}
	return (0);
}