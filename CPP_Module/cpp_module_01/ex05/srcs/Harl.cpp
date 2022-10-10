/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:33:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/10 11:35:15 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.hpp"

Harl::Harl(void) {
	for (size_t i=0; i<FUNC_ARR_SIZE; i++) {
		func[i] = &Harl::invalid_behavior;
	}
	func[hash("debug")] = &Harl::debug;
	func[hash("info")] = &Harl::info;
	func[hash("warning")] = &Harl::warning;
	func[hash("error")] = &Harl::error;
	return;
}

Harl::~Harl(void) {
	return;
}

void	Harl::debug(void) {
	std::cout << "DEBUG: ...\n";
	return;
}

void	Harl::info(void) {
	std::cout << "INFO: ...\n";
	return;
}

void	Harl::warning(void) {
	std::cout << "WARNING: ...\n";
	return;
}

void	Harl::error(void) {
	std::cout << "ERROR: ...\n";
	return;
}

void	Harl::invalid_behavior(void) {
	std::cerr << "\033[31mError: Invalid behavior\033[0m\n";
	return;
}

size_t	Harl::hash(const std::string &level) {
	const size_t	PRIME = 31;
	size_t			ret = 0;

	for (size_t i=0; i<level.length(); i++) {
		ret += (level[i] * (int) my_pow(PRIME, i)) % FUNC_ARR_SIZE;
	}
	return (ret % FUNC_ARR_SIZE);
}

size_t	Harl::my_pow(size_t base, int power) {
	size_t	ret = 1;

	while (power--) {
		ret = (ret * base) % FUNC_ARR_SIZE;
	}
	return (ret);
}

void	Harl::complain(const std::string &level) {
	(this->*func[hash(level)])();
	return;
}