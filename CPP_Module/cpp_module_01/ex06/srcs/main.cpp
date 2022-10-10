/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:54:29 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/10 14:13:17 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "\033[31mUsage: ./harlFilter <Things to complain>\033[0m" << '\n';
		return (0);
	}
	
	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}