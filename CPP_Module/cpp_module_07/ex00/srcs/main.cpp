/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:34:49 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/18 15:50:31 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../incs/whatever.hpp"

int	main(void) {
	{
		int	a = 2;
		int	b = 3;

		ft::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << '\n';
		std::cout << "min(a, b) = " << ft::min( a, b ) << '\n';
		std::cout << "max(a, b) = " << ft::max( a, b ) << '\n';
	}
	{
		std::string	c = "chaine1";
		std::string	d = "chaine2";

		ft::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << '\n';
		std::cout << "min(c, d) = " << ft::min( c, d ) << '\n';
		std::cout << "max(c, d) = " << ft::max( c, d ) << '\n';
	}
	return (0);
}