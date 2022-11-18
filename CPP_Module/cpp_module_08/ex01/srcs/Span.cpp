/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:51:57 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/18 17:04:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"

Span::Span(void) {}

Span::Span(unsigned int n): _size(n) {}

Span::Span(const Span &ref) {
	*this = ref;
}

Span	&Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->_vec.clear();
		this->_size = rhs._size;
		for (size_t i=0; i<rhs._vec.size(); i++) {
			this->_vec.push_back(rhs._vec[i]);
		}
	}
	return (*this);
}

Span::~Span(void) {}

void	Span::addNumber(int num) {
	if (this->_size <= this->_vec.size()) {
		throw std::exception();
	}

	for (size_t i=0; i<this->_vec.size(); i++) {
		if (this->_vec[i] == num) {
			throw std::exception();
		}
		if (num < this->_vec[i]) {
			this->_vec.insert(this->_vec.begin() + i, num);
			return;
		}
	}
	this->_vec.push_back(num);
}

int		Span::shortestSpan(void) {
	if (this->_vec.size() <= 1) {
		throw std::exception();
	}
	
	int min = 2147483647;
	for (size_t i=0; i<this->_vec.size()-1; i++) {
		int	span = this->_vec[i+1] - this->_vec[i];
		if (span < min) {
			min = span;
		}
	}
	return (min);
}

int		Span::longestSpan(void) {
	if (this->_vec.size() <= 1) {
		throw std::exception();
	}
	
	return (this->_vec[this->_vec.size()-1] - this->_vec[0]);
}

void	Span::printVec(void) {
	for (size_t i=0; i<this->_vec.size(); i++) {
		std::cout << this->_vec[i] << " ";
	}
	std::cout << std::endl;
}