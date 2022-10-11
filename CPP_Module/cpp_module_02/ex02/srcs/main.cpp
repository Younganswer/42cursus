/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:54:29 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/11 14:39:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

int	main(void) {
	Fixed	a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << '\n';
	std::cout << ++a << '\n';
	std::cout << a << '\n';
	std::cout << a++ << '\n';
	std::cout << a << '\n';
	std::cout << b << '\n';
	std::cout << Fixed::max(a, b) << '\n';
	std::cout << a / Fixed(0) << '\n';
	return (0);
}