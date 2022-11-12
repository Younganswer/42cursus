/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:34:49 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/12 21:33:50 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Convert.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "\033[31mUsage: ./convert [string]\33[0m" << '\n';
		return (1);
	}
	std::cout << std::fixed;
	std::cout.precision(1);
	Convert	convert(argv[1]);
	convert.print();
	return (0);
}