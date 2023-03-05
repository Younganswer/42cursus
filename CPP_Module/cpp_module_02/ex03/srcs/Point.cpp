#include "../incs/Point.hpp"

Point::Point(void): _x(0), _y(0) {}
Point::Point(const float x, const float y): _x(x), _y(y) {}
Point::Point(const Fixed &x, const Fixed &y): _x(x), _y(y) {}
Point::Point(const Point &point): _x(point._x), _y(point._y) {}
Point::~Point(void) {}

Point	&Point::operator=(const Point &point) {
	if (this != &point) {
		this->~Point();
		new (this) Point(point);
	}
	return (*this);
}

// Getter
Fixed		Point::getX(void) { return (this->_x); }
Fixed		Point::getY(void) { return (this->_y); }
const Fixed	&Point::getX(void) const { return (this->_x); }
const Fixed	&Point::getY(void) const { return (this->_y); }

// Operator Overload
const Point	Point::operator-(const Point &point) const {
	return (Point(this->_x-point._x, this->_y-point._y));
}