/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:54:29 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/09 23:52:08 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Replace.hpp"
#include "../incs/utils.hpp"

int	main(int argc, char **argv) {
	if (argc != 4)
		exit_with_error("Invalid arguments\nUsage: ./replace <filename> <string1> <string2>", 0);

	Replace	replace(argv[1], argv[2], argv[3]);
	try {
		replace.replace();
	} catch (std::string err) {
		exit_with_error(err, 1);
	}
	return (0);
}