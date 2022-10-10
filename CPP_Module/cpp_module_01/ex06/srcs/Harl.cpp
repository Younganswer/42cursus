/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:33:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/10 14:12:26 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.hpp"

Harl::Harl(void) {
	for (size_t i=0; i<FUNC_ARR_SIZE; i++) {
		func[i] = &Harl::undefined_behavior;
	}
	func[hash("DEBUG")] = &Harl::debug;
	func[hash("INFO")] = &Harl::info;
	func[hash("WARNING")] = &Harl::warning;
	func[hash("ERROR")] = &Harl::error;
	return;
}

Harl::~Harl(void) {
	return;
}

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]\n";
	std::cout << "Message about debug\n";
	return;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]\n";
	std::cout << "Message about infomation\n";
	return;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]\n";
	std::cout << "Message about warning\n";
	return;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]\n";
	std::cout << "Message about error\n";
	return;
}

void	Harl::undefined_behavior(void) {
	std::cout << "[ Probably complaining about insignificant problems ]\n";
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