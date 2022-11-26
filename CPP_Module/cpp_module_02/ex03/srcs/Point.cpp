/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:01:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 11:56:42 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.hpp"

Point::Point(void): _x(0), _y(0) {}
Point::Point(float x, float y): _x(x), _y(y) {}
Point::Point(Fixed x, Fixed y) { this->_x = x; this->_y = y; }
Point::Point(const Point &point) { (*this) = point; }
Point::~Point(void) {}

Point	&Point::operator=(const Point &point) {
	if (this != &point) {
		this->_x = point._x;
		this->_y = point._y;
	}
	return (*this);
}

// Getter
Fixed		Point::getX(void) { return (this->_x); }
Fixed		Point::getY(void) { return (this->_y); }
const Fixed	Point::getX(void) const { return (this->_x); }
const Fixed	Point::getY(void) const { return (this->_y); }

// Operator Overload
const Point	Point::operator-(const Point point) const {
	return (Point(this->_x-point._x, this->_y-point._y));
}