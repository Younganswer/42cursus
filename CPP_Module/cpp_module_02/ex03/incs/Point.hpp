#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;
		
		static float	cross_product(const Point &p1, const Point &p2);

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &ref);
		~Point(void);
		Point	&operator=(const Point &rhs);

		// Getter
		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;

		// Util
		static bool		bsp(const Point a, const Point b, const Point c, const Point point);

		// Operator Overload
		const Point	operator-(const Point &point) const;
};

#endif