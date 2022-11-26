/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:54:29 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 11:56:54 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../incs/Fixed.hpp"
#include "../incs/Point.hpp"

int	main(void) {
	{
		Point	a(0, 0), b(0, 3), c(4, 0);
		Point	target(2, 1);
		std::cout << "Target is " << ((bsp(a, b, c, target)) ? "inside" : "outside or on the line") <<  " of the triangle\n";
	}
	return (0);
}