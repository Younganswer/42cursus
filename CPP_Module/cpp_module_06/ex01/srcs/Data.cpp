/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:58:06 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/12 22:12:21 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Data.hpp"

_Data::_Data(void) {}

_Data::_Data(const std::string &s1, const std::string &s2, int n) {
	this->s1 = std::string(s1.c_str());
	this->s2 = std::string(s2.c_str());
	this->n = n;
}

_Data::~_Data(void) {}

uintptr_t	serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}