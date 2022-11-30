/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:54:29 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/30 16:41:55 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

int	main(void) {
	{
		const int	b_init = 10;
		const float	c_init = 42.42f;
		
		Fixed		a;
		Fixed const b(b_init);
		Fixed const c(c_init);
		Fixed const d(b);

		a = Fixed(1234.4321f);

		std::cout << "a is " << a << '\n';
		std::cout << "b is " << b << '\n';
		std::cout << "c is " << c << '\n';
		std::cout << "d is " << d << '\n';

		std::cout << "a is " << a.toInt() << " as integer\n";
		std::cout << "b is " << b.toInt() << " as integer\n";
		std::cout << "c is " << c.toInt() << " as integer\n";
		std::cout << "d is " << d.toInt() << " as integer\n";
	}
	return (0);
}