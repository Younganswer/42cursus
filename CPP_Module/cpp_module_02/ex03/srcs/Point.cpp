/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:01:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/19 12:10:59 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.hpp"

Point::Point(void): x(0), y(0) {}

Point::Point(float x, float y): x(x), y(y) {}

Point::Point(Fixed x, Fixed y) {
	this->x = x;
	this->y = y;
	return;
}

Point::Point(const Point &point) {
	if (this != &point)
		(*this) = point;
	return;
}

Point	&Point::operator=(const Point &point) {
	if (this != &point) {
		this->x = point.x;
		this->y = point.y;
	}
	return (*this);
}

Fixed	Point::getX(void) {
	return (x);
}

const Fixed	Point::getX(void) const {
	return (x);
}

Fixed	Point::getY(void) {
	return (y);
}

const Fixed	Point::getY(void) const {
	return (y);
}

const Point	Point::operator-(const Point point) const {
	return (Point(this->x-point.x, this->y-point.y));
}

Point::~Point(void) {}