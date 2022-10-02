/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:24:43 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/02 17:33:35 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

bool	print_argv(char *str);

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i=1; i<argc; i++) {
		print_argv(argv[i]);
	}
	std::cout << '\n';
	return (0);
}

bool	print_argv(char *str) {
	for (int i=0; str[i]; i++)
		std::cout << (('a' <= str[i] && str[i] <= 'z') ? (char) (str[i] - 32) : str[i]);
	return (true);
}