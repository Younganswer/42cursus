/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:24:43 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 16:34:33 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		for (int i=1; i<argc; i++) {
			std::string str(argv[i]);
			for (size_t j=0; j<str.length(); j++) {
				std::cout << (char) std::toupper(str[j]);
			}
		}
	}
	std::cout << '\n';
	return (0);
}
