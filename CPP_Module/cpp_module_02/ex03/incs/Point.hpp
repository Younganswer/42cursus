/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:57:33 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/19 12:05:31 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
private:
	Fixed	x;
	Fixed	y;

public:
	Point(void);
	Point(float x, float y);
	Point(Fixed x, Fixed y);
	Point(const Point &point);
	Point	&operator=(const Point &point);
	~Point(void);

	Fixed		getX(void);
	const Fixed	getX(void) const;
	Fixed		getY(void);
	const Fixed	getY(void) const;

	const Point	operator-(const Point point) const;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif